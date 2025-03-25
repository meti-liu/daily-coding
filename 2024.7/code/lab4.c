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
    MODE1,
    MODE2
};

enum mode_t mode = MODE1;
char buf[10] = {0};
unsigned int distance = 0;
unsigned char speed = 0;
unsigned char position = 50;
char key = 0;

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

    while (1) {
        // 读取按键键值
        key = s1_key_value_get(s1_key_info);

        // 根据按键值切换模式
        if (key == '1' && mode != MODE1) {
            mode = MODE1;
            update_display("MODE1");
            delay_ms(1000);
        } else if (key == '2' && mode != MODE2) {
            mode = MODE2;
            update_display("MODE2");
            delay_ms(1000);
        }

        // 根据当前模式执行相应功能
        switch (mode) {
            case MODE1:
                mode1_obstacle_avoidance();
                break;
            case MODE2:
                mode2_traffic_light_simulation();
                break;
            default:
                break;
        }

        // 延时100ms
        delay_ms(100);
    }
}

void mode1_obstacle_avoidance() {
    update_display("OBSTACLE");

    // 检测前方、左方、右方、后方障碍物
    if (key == '2') {
        distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
        update_display("FRONT");
    } else if (key == '4') {
        distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
        update_display("LEFT");
    } else if (key == '6') {
        distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
        update_display("RIGHT");
    } else if (key == '8') {
        distance = s6_ultrasonic_distance_get(s6_ultrasonic_info);
        update_display("BACK");
    }

    // 更新 LED 灯颜色
    update_led_color(distance);

    // 调整速度和方向
    adjust_speed_and_position_based_on_distance();
}

void mode2_traffic_light_simulation() {
    update_display("TRAFFIC");
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
    if (key == '2' && distance < 250) {
        speed = 0;
        e2_fan_speed_set(e2_fan_info, speed);
    } else if (key == '8' && distance < 250) {
        speed = 100;
        e2_fan_speed_set(e2_fan_info, speed);
    } else if (key == '4' && distance < 250) {
        position = 100;
        e3_curtain_position_set(e3_curtain_info, position);
    } else if (key == '6' && distance < 250) {
        position = 0;
        e3_curtain_position_set(e3_curtain_info, position);
    } else {
        speed = 50;
        e2_fan_speed_set(e2_fan_info, speed);
        position = 50;
        e3_curtain_position_set(e3_curtain_info, position);
    }
}
