#include <stdio.h>
#include "delay.h"
#include "e1.h"
#include "e3.h"
#include "s1.h"

int main()
{
	char buf[10] = {0};
	unsigned char target_position = 0;

	unsigned char real_position;
	/* 窗帘电机状态，0表示电机停止工作，1表示电机正在工作 */
	unsigned char real_status;


	e1_tube_info = e1_tube_init();
	e3_curtain_info = e3_curtain_init();
	/* 将窗帘目标位置设置为target_position */
	e3_curtain_position_set(e3_curtain_info, target_position);
	char key = 0;

	s1_key_info = s1_key_init();
	int k=10;

	
	while(1)
	{	
		real_status = e3_curtain_status_get(e3_curtain_info);		
		real_position = e3_curtain_position_get(e3_curtain_info);
		/* 将窗帘电机工作状态和窗帘当前实际位置转换为字符串并写入buf */
		sprintf(buf, "%d.%03d", real_status, real_position);
		/* 在数码管上显示buf中的字符串 */
		e1_tube_str_set(e1_tube_info, buf);
		/* 如果窗帘当前实际位置已经达到设置的目标位置且电机已经停止工作 */
		
		
		key = s1_key_value_get(s1_key_info);
		if(real_position == target_position && real_status == 0)
		{
			/* 延时1000ms */
			delay_ms(1000);
			
			
			if(key=='*')
			{
				if(target_position==0||target_position==100) k*=-1;
				target_position+=k;
			}

			/* 将窗帘位置设置为target_position */
			e3_curtain_position_set(e3_curtain_info, target_position);
		}
			
	}
}