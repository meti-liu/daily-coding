#include <stdio.h>
#include "delay.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "s1.h"
#include "s6.h"

// 定义模式状态
enum mode_t {
    INIT,
    MODE_SELECTION,
    MODE1,
    MODE2,
    DETECT_FRONT,
    DETECT_LEFT,
    DETECT_RIGHT,
    DETECT_BACK
};

enum mode_t mode = INIT;
char buf[10] = {0};
unsigned int distance = 0;
unsigned char position = 50;
unsigned char speed = 50;

// 前向声明
void update_display(const char* message);
void update_display_distance(unsigned int distance);
void mode1_obstacle_avoidance();
void detect_obstacle();
void adjust_speed_and_position_based_on_distance(unsigned int distance);

int main() {
    // 初始化设备
    e1_tube_info = e1_tube_init();
    e1_led_info = e1_led_init(); // LED灯初始化
    e2_fan_info = e2_fan_init();
    e3_curtain_info = e3_curtain_init();
    s1_key_info = s1_key_init();
    s6_ultrasonic_info = s6_ultrasonic_init();

    // 初始状态显示
    update_display("HELO");

    while (1) {
        // 读取按键键值
        char key = s1_key_value_get(s1_key_info);

        // 高优先级处理#
        if (key == '#') {
            mode = MODE_SELECTION;
            update_display("MODE");
            delay_ms(500);
            continue; // 跳过其他处理，立即返回选择模式状态
        }

        if (mode == INIT) {
            update_display("HELO");
            mode = MODE_SELECTION;
        } else if (mode == MODE_SELECTION) {
            // 处理按键输入
            if (key == '1') {
                mode = MODE1;
                update_display("M1");
                delay_ms(1000);
            } else if (key == '2') {
                mode = MODE2;
                update_display("M2");
                delay_ms(1000);
            }
        } else if (mode == MODE1) {
            mode1_obstacle_avoidance();
        } else if (mode == DETECT_FRONT || mode == DETECT_LEFT || mode == DETECT_RIGHT || mode == DETECT_BACK) {
            detect_obstacle();
        }

        // 延时500ms
        delay_ms(500);
    }
}

void update_display(const char* message) {
    char buf[5] = {0}; // 四位数码管显示
    snprintf(buf, sizeof(buf), "%s", message);
    e1_tube_str_set(e1_tube_info, buf);
}

void update_display_distance(unsigned int distance) {
    char buf[5] = {0}; // 四位数码管显示
    snprintf(buf, sizeof(buf), "%4d", distance);
    e1_tube_str_set(e1_tube_info, buf);
}

void mode1_obstacle_avoidance() {
    char local_key = s1_key_value_get(s1_key_info);
    if (local_key == '2') {
        mode = DETECT_FRONT;
        update_display("FRONT");
        delay_ms(2000);
    } else if (local_key == '4') {
        mode = DETECT_LEFT;
        update_display("LEFT");
        delay_ms(2000);
    } else if (local_key == '6') {
        mode = DETECT_RIGHT;
        update_display("RIGHT");
        delay_ms(2000);
    } else if (local_key == '8') {
        mode = DETECT_BACK;
        update_display("BACK");
        delay_ms(2000);
    }

    // 如果按下#键退出
    if (local_key == '#') {
        mode = MODE_SELECTION;
        update_display("MODE");
        delay_ms(500);
    }
}

void detect_obstacle() {
    while (1) {
        distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
        update_display_distance(distance);
        adjust_speed_and_position_based_on_distance(distance);

        // 如果按下#键退出
        char local_key = s1_key_value_get(s1_key_info);
        if (local_key == '#') {
            mode = MODE_SELECTION;
            update_display("MODE");
            break;
        }

        // 延时500ms
        delay_ms(500);
    }
}

void adjust_speed_and_position_based_on_distance(unsigned int distance) {
    if (distance < 350) {
        e1_led_rgb_set(e1_led_info, 100, 0, 0); // 红灯快速闪烁
        delay_ms(200);
        e1_led_rgb_set(e1_led_info, 0, 0, 0);
        delay_ms(200);

        if (mode == DETECT_FRONT) {
            speed = 0; // 减速
            e2_fan_speed_set(e2_fan_info, speed);
        } else if (mode == DETECT_BACK) {
            speed = 100; // 加速
            e2_fan_speed_set(e2_fan_info, speed);
        } else if (mode == DETECT_LEFT) {
            position = 100; // 向右转
            e3_curtain_position_set(e3_curtain_info, position);
        } else if (mode == DETECT_RIGHT) {
            position = 0; // 向左转
            e3_curtain_position_set(e3_curtain_info, position);
        }
    } else if (distance < 500) {
        e1_led_rgb_set(e1_led_info, 100, 100, 0); // 黄灯闪烁
        delay_ms(500);
        e1_led_rgb_set(e1_led_info, 0, 0, 0);
        delay_ms(500);
    } else {
        e1_led_rgb_set(e1_led_info, 0, 100, 0); // 绿灯常亮
    }
}
