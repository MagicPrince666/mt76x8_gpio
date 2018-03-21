#include "sys.h"

#define MEM_REG 1

int main(int argc,char** argv)
{

#if MEM_REG

	if (gpio_mmap())
		return -1;

	printf("get pin 14 input %d\n", mt76x8_gpio_get_pin(14));
	printf("get pin 15 input %d\n", mt76x8_gpio_get_pin(15));
	printf("get pin 16 input %d\n", mt76x8_gpio_get_pin(16));
	printf("get pin 17 input %d\n", mt76x8_gpio_get_pin(17));

	
	// printf("set pin 14 output 1\n");
	// mt76x8_gpio_set_pin_direction(14, 1);
	// mt76x8_gpio_set_pin_value(14, 1);
	// printf("set pin 15 output 0\n");
	// mt76x8_gpio_set_pin_direction(15, 1);
	// mt76x8_gpio_set_pin_value(15, 0);
	// printf("set pin 16 output 1\n");
	// mt76x8_gpio_set_pin_direction(16, 1);
	// mt76x8_gpio_set_pin_value(16, 1);
	// printf("set pin 17 output 0\n");
	// mt76x8_gpio_set_pin_direction(17, 1);
	// mt76x8_gpio_set_pin_value(17, 0);

    mt76x8_gpio_set_pin_direction(14, 1);
    mt76x8_gpio_set_pin_direction(15, 1);
    mt76x8_gpio_set_pin_direction(16, 1);
    mt76x8_gpio_set_pin_direction(17, 1);

    mt76x8_gpio_set_pin_value(14, 1);
    mt76x8_gpio_set_pin_value(15, 1);
    mt76x8_gpio_set_pin_value(16, 1);
    mt76x8_gpio_set_pin_value(17, 1);
    while (1)
	{
		mt76x8_gpio_set_pin_value(14, 1);
        mt76x8_gpio_set_pin_value(15, 0);
        mt76x8_gpio_set_pin_value(16, 1);
        mt76x8_gpio_set_pin_value(17, 0);
        usleep(100000);
		mt76x8_gpio_set_pin_value(14, 0);
        mt76x8_gpio_set_pin_value(15, 1);
        mt76x8_gpio_set_pin_value(16, 0);
        mt76x8_gpio_set_pin_value(17, 1);
        usleep(100000);    
	}
	close(gpio_mmap_fd);

#else

    FILE* set_export;
    int gpio_fd[4];

    //打开设备节点
	set_export = fopen ("/sys/class/gpio/export", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/export!\n");
	else fprintf(set_export,"14");
	fclose(set_export);
    set_export = fopen ("/sys/class/gpio/export", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/export!\n");
	else fprintf(set_export,"15");
	fclose(set_export);
    set_export = fopen ("/sys/class/gpio/export", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/export!\n");
	else fprintf(set_export,"16");
	fclose(set_export);
    set_export = fopen ("/sys/class/gpio/export", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/export!\n");
	else fprintf(set_export,"17");
	fclose(set_export);
	
    printf("enable gpio\n");

    //设置成输出
	set_export = fopen ("/sys/class/gpio/gpio14/direction", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/gpio14/direction!\n");
	else fprintf(set_export,"out");
	fclose(set_export);//设置
    set_export = fopen ("/sys/class/gpio/gpio15/direction", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/gpio15/direction!\n");
	else fprintf(set_export,"out");
	fclose(set_export);//设置
    set_export = fopen ("/sys/class/gpio/gpio16/direction", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/gpio16/direction!\n");
	else fprintf(set_export,"out");
	fclose(set_export);//设置
    set_export = fopen ("/sys/class/gpio/gpio17/direction", "w");
	if(set_export == NULL)printf ("Can't open /sys/class/gpio/gpio17/direction!\n");
	else fprintf(set_export,"out");
	fclose(set_export);//设置

    printf("set gpio out\n");

    gpio_fd[0] = open ("/sys/class/gpio/gpio14/value", O_RDWR);
    gpio_fd[1] = open ("/sys/class/gpio/gpio15/value", O_RDWR);
    gpio_fd[2] = open ("/sys/class/gpio/gpio16/value", O_RDWR);
    gpio_fd[3] = open ("/sys/class/gpio/gpio17/value", O_RDWR);

	while (1)
	{
        write(gpio_fd[0],"1",1);
        write(gpio_fd[1],"1",1);
        write(gpio_fd[2],"1",1);
        write(gpio_fd[3],"1",1);
        usleep(100000);
        write(gpio_fd[0],"0",1);
        write(gpio_fd[1],"0",1);
        write(gpio_fd[2],"0",1);
        write(gpio_fd[3],"0",1);
        usleep(100000);
	}
    close(gpio_fd[0]);
    close(gpio_fd[1]);
    close(gpio_fd[2]);
    close(gpio_fd[3]);

#endif

	return 0;
}