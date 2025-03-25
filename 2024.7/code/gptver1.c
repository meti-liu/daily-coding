#include <stdio.h>
#include "u1.h"
#include "delay.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "s1.h"
#include "s6.h"

// 定义状态
enum mode_t {
    INIT,
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
unsigned char speed = 0;
unsigned char position = 50;
char key = 0;
char last_key = 0;

// 函数声明
void mode1_obstacle_avoidance();
void mode2_traffic_light_simulation();
void update_display(const char* message);
void update_led_color(unsigned int distance);
void adjust_speed_and_position_based_on_distance();

int main() {
    // 初始化设备
    e1_tube_info = e1_tube_init();
    e1_led_info = e1_led_init();
    e2_fan_info = e2_fan_init();
    e3_curtain_info = e3_curtain_init();
    s1_key_info = s1_key_init();
    s6_ultrasonic_info = s6_ultrasonic_init();

    // 初始状态显示
    update_display("HELO");

    while (1) {
        // 读取按键键值
        key = s1_key_value_get(s1_key_info);

        // 处理按键输入
        if (key == '#') {
            if (last_key == '1') {
                mode = MODE1;
                update_display("MODE1");
                delay_ms(1000);
            } else if (last_key == '2') {
                mode = MODE2;
                update_display("MODE2");
                delay_ms(1000);
            } else if (mode == MODE1) {
                if (last_key == '2') {
                    mode = DETECT_FRONT;
                    update_display("FRONT");
                } else if (last_key == '4') {
                    mode = DETECT_LEFT;
                    update_display("LEFT");
                } else if (last_key == '6') {
                    mode = DETECT_RIGHT;
                    update_display("RIGHT");
                } else if (last_key == '8') {
                    mode = DETECT_BACK;
                    update_display("BACK");
                }
            }
        } else {
            last_key = key;
        }

        // 根据当前模式执行相应功能
        switch (mode) {
            case MODE1:
                update_display("MODE1");
                break;
            case MODE2:
                mode2_traffic_light_simulation();
                break;
            case DETECT_FRONT:
                distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
                update_display("FRONT");
                update_led_color(distance);
                adjust_speed_and_position_based_on_distance();
                break;
            case DETECT_LEFT:
                distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
                update_display("LEFT");
                update_led_color(distance);
                adjust_speed_and_position_based_on_distance();
                break;
            case DETECT_RIGHT:
                distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
                update_display("RIGHT");
                update_led_color(distance);
                adjust_speed_and_position_based_on_distance();
                break;
            case DETECT_BACK:
                distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
                update_display("BACK");
                update_led_color(distance);
                adjust_speed_and_position_based_on_distance();
                break;
            default:
                update_display("HELO");
                break;
        }

        // 延时100ms
        delay_ms(100);
    }
}

void mode1_obstacle_avoidance() {
    // 已在主循环中处理
}

void mode2_traffic_light_simulation() {
    // 模拟红绿灯逻辑
    for (int i = 8; i >= 1; i--) {
        sprintf(buf, "%dG", i);
        e1_tube_str_set(e1_tube_info, buf);
        e1_led_rgb_set(e1_led_info, 0, 100, 0); // 绿灯
        delay_ms(1000);
    }
    for (int i = 3; i >= 1; i--) {
        sprintf(buf, "%dY", i);
        e1_tube_str_set(e1_tube_info, buf);
        e1_led_rgb_set(e1_led_info, 100, 100, 0); // 黄灯闪烁
        delay_ms(500);
        e1_led_rgb_set(e1_led_info, 0, 0, 0);
        delay_ms(500);
    }
    for (int i = 15; i >= 1; i--) {
        sprintf(buf, "%dR", i);
        e1_tube_str_set(e1_tube_info, buf);
        e1_led_rgb_set(e1_led_info, 100, 0, 0); // 红灯
        delay_ms(1000);
    }
}

void update_display(const char* message) {
    char buf[10] = {0}; // 假设消息不会超过 9 个字符
    snprintf(buf, sizeof(buf), "%s", message);
    e1_tube_str_set(e1_tube_info, buf);
}

void update_led_color(unsigned int distance) {
    if (distance > 500) {
        e1_led_rgb_set(e1_led_info, 0, 100, 0); // 绿灯
    } else if (distance > 350) {
        e1_led_rgb_set(e1_led_info, 100, 100, 0); // 黄灯闪烁
        delay_ms(500);
        e1_led_rgb_set(e1_led_info, 0, 0, 0);
        delay_ms(500);
    } else if (distance > 250) {
        e1_led_rgb_set(e1_led_info, 100, 0, 0); // 红灯快速闪烁
        delay_ms(200);
        e1_led_rgb_set(e1_led_info, 0, 0, 0);
        delay_ms(200);
    } else {
        e1_led_rgb_set(e1_led_info, 100, 0, 0); // 红灯常亮
    }
}

void adjust_speed_and_position_based_on_distance() {
    if (distance < 250) {
        if (mode == DETECT_FRONT) {
            speed = 0;
        } else if (mode == DETECT_BACK) {
            speed = 100;
        } else if (mode == DETECT_LEFT) {
            position = 100;
        } else if (mode == DETECT_RIGHT) {
            position = 0;
        }
    } else {
        speed = 50;
        position = 50;
    }
    e2_fan_speed_set(e2_fan_info, speed);
    e3_curtain_position_set(e3_curtain_info, position);
}
