#include <stdio.h>
#include "delay.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "s1.h"
#include "s2.h"

// 全局缓冲区
char buf[10] = {0};
unsigned char position = 50;
unsigned char speed = 50;
char current_mode = '0';

void update_display(char* message);
void mode3_direction_control();

int main() {
    char key = 0;

    // 初始化设备
    e1_tube_info = e1_tube_init();
    s1_key_info = s1_key_init();
    s2_imu_info = s2_imu_init();
    e1_led_info = e1_led_init(); // 初始化 LED 灯
    e2_fan_info = e2_fan_init(); // 初始化 风扇
    e3_curtain_info = e3_curtain_init(); // 初始化 窗帘

    // 初始状态显示
    update_display("HELO");

    while (1) {
        // 读取按键键值
        key = s1_key_value_get(s1_key_info);

        // 切换到 MODE3
        if (key == '#') {
            current_mode = '3';
        }

        // 如果在 MODE3，持续检测并更新汽车的方向和速度
        if (current_mode == '3') {
            mode3_direction_control();
        }

        // 延时500ms
        delay_ms(500);
    }
}

void update_display(char* message) {
    e1_tube_str_set(e1_tube_info, message);
}

void mode3_direction_control() {
    s2_imu_t imu_value;

    // 读取加速度传感器的值
    imu_value = s2_imu_value_get(s2_imu_info);

    // 根据加速度值调整汽车的方向和速度
    if (imu_value.acc_y > 3) {
        position += 5; // 向左转
        if (position > 100) position = 100; // 限制最大值为100
    } else if (imu_value.acc_y < -3) {
        position -= 5; // 向右转
        if (position < 0) position = 0; // 限制最小值为0
    }

    if (imu_value.acc_x > 5) {
        speed += 10; // 加速
        if (speed > 100) speed = 100; // 限制最大值为100
    } else if (imu_value.acc_x > 0) {
        speed += 5; // 加速
        if (speed > 100) speed = 100; // 限制最大值为100
    } else if (imu_value.acc_x < -5) {
        speed -= 10; // 减速
        if (speed < 0) speed = 0; // 限制最小值为0
    } else if (imu_value.acc_x < 0) {
        speed -= 5; // 减速
        if (speed < 0) speed = 0; // 限制最小值为0
    }

    // 更新汽车的方向和速度
    e3_curtain_position_set(e3_curtain_info, position);
    e2_fan_speed_set(e2_fan_info, speed);

    // 显示当前的方向和速度
    snprintf(buf, sizeof(buf), "%3d%3d", position, speed);
    update_display(buf);

    // 延时500ms
    delay_ms(50);
}
