#include <stdio.h>
#include "delay.h"
#include "e1.h"
#include "s1.h"
#include "e3.h"

unsigned char position = 0;
char buf[10] = {0};
int k=10;

void adjust_position();

int main()
{
    char key = 0;


    e1_tube_info = e1_tube_init();
    s1_key_info = s1_key_init();
    e3_curtain_info = e3_curtain_init();

    e3_curtain_position_set(e3_curtain_info, position);
    // 数码管显示默认值 "HEL0"
    e1_tube_str_set(e1_tube_info, "HEL0");

    while(1)
    {	
        key = s1_key_value_get(s1_key_info);

        // 根据按键值调整窗帘位置
        if(key == '*')
        {
            adjust_position();
        }

        // 延时100ms
        delay_ms(100);
    }
}

void adjust_position()
{
    // 获取当前窗帘位置
    unsigned char position = e3_curtain_position_get(e3_curtain_info);

    if (position == 0 || position == 100) k *= -1;
        position += k;
        if (position > 100) position = 100;
        if (position < 0) position = 0;


    e3_curtain_position_set(e3_curtain_info, position);


    sprintf(buf, "%03d", position);
    e1_tube_str_set(e1_tube_info, buf);
}
