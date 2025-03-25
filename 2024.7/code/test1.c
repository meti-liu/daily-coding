#include <stdio.h>
#include "delay.h"
#include "e1.h"
#include "e3.h"
#include "s1.h"
#include "s6.h"

// 前向声明
void update_display(const char* message);

int main() {
    char key = 0;
    unsigned int distance = 0;
    unsigned char position = 50;
    char buf[5] = {0}; // 四位数码管显示

    // 初始化设备
    e1_tube_info = e1_tube_init();
    e3_curtain_info = e3_curtain_init();
    s1_key_info = s1_key_init();
    s6_ultrasonic_info = s6_ultrasonic_init();

    // 初始状态显示
    update_display("HELO");

    while (1) {
        // 读取按键键值
        key = s1_key_value_get(s1_key_info);

        // 如果按键是1，启动距离检测
        if (key == '1') {
            while (1) {
                distance = s6_ultrasonic_distance_get(s6_ultrasonic_info)

                // 将距离值转换为字符串并显示在数码管上
                snprintf(buf, sizeof(buf), "%4d", distance); // 确保占用四位数码管
                e1_tube_str_set(e1_tube_info, buf);

                // 根据距离调整E3的位置
                if (distance < 250) {
                    position = 0;  // 向左转
                } else if (distance < 500) {
                    position = 100;  // 向右转
                } else {
                    position = 50;  // 直行
                }

                // 设置E3的位置
                e3_curtain_position_set(e3_curtain_info, position);

                // 延时500ms
                delay_ms(500);

                // 读取按键键值
                key = s1_key_value_get(s1_key_info);
                if (key == '#') {
                    break;  // 按下#键退出距离检测
                }
            }
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
