#include <stdio.h>
#include "delay.h"
#include "e1.h"
#include "s2.h"

int main()
{
	char buf[10] = {0};
	s2_imu_t imu_value;

	/* 数码管初始化 */
	e1_tube_info = e1_tube_init();
	/* 加速度&角速度传感器初始化 */
	s2_imu_info = s2_imu_init();

	while(1)
	{	
		/* 读取加速度&角速度传感器测量结果（m/s2、rad/s） */
		imu_value = s2_imu_value_get(s2_imu_info);
		/* 将z轴的角速度值转换为字符串并写入buf */
		sprintf(buf, "%.1f", imu_value.gyr_z);
		/* 在数码管上显示buf中的字符串 */
		e1_tube_str_set(e1_tube_info, buf);
		/* 延时100ms */
		delay_ms(100);
	}
}
