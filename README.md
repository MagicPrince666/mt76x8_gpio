# mt76x8_gpio
驱动MT76x8的gpio
感谢佐须之男的寄存器库
这里没做C++的类封装，只是比较糙的C++代码

非寄存器操作部分，就是进入/sys/class/gpio/目录，对该目录下的export文件进行写操作，来激活gpio。

比如说把"14"写入export,gpio14就会激活，/sys/class/gpio/目录下就会出现gpio14文件夹。该文件夹下有几个文件，我们只关心direction和value这两个文件。

direction是设置输入输出的，写入"out"，对应的gpio就设置成输出，写入"in"则为输入。

value是gpio的值，对于输出，在该文件下写"0"或"1",对于输入，读取该文件就行。

shell方式如下 
#激活gpio14
echo 14 > /sys/class/gpio/export
#设置gpio14为输出
echo out > /sys/class/gpio/gpio14/direction
#设置高电平
echo 1 > /sys/class/gpio/gpio14/value
#设置低电平
echo 0 > /sys/class/gpio/gpio14/value

#激活gpio15
echo 15 > /sys/class/gpio/export
#设置gpio15为输入
echo in > /sys/class/gpio/gpio15/direction
#读取gpio电平
cat /sys/class/gpio/gpio15/value
