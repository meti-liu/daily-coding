#include....
void adjust_pos();
void adjust_led(char key);
void adjust_speed(char key);
void display(unsigned char val);

int main()
{
    //init初始化

    while(1)
    {
        key = s1_key_value_get(s1_key_info);

    
        if(key == '*') adjust_pos();

        else if(key=='#') adjust_speed(key);

        else if(key >= '1' && key <= '9') adjust_led(key);

        // 延时100ms
        delay_ms(500);
    }
}

void....
{
    ....
}

void adjust_led(char key)
{
    switch(key)
    {
        case '1':
            if (r < 100) r+=10;
            e1_led_rgb_set(e1_led_info, r, 0, 0);
            display(r);
            break;
        case '2':
            if (g < 100) g+=10;
            e1_led_rgb_set(e1_led_info, 0, g, 0);
            display(g);
            break;
        case '3':
        .....
    }
}