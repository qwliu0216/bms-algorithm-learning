#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    const double voltage_v = 4.18;
    const double temperature_c = 43.5;
    const double soc_percent = 18.0;
    const unsigned int cycle_count = 125U;

    const bool voltage_valid = voltage_v >= 2.5 && voltage_v <= 4.3;
    const bool temperature_valid = temperature_c >= -20.0 && temperature_c <= 60.0;
    const bool soc_valid = soc_percent >= 0.0 && soc_percent <= 100.0;

    if (!voltage_valid || !temperature_valid || !soc_valid) {
        printf("Invalid sample: check the sensor range.\n");
        return 1;//这是从 main 函数提前退出，并且用返回值 1 告诉"外部世界"：这次程序运行失败了
    }

    const char *status = "NORMAL"; //把 "ALARM" 的地址赋给 status status存的是N的地址
    if (voltage_v > 4.20 || temperature_c > 45.0) {
        status = "ALARM";//把 "ALARM" 的地址赋给 status status存的是A的地址
    } else if (voltage_v < 3.00 || soc_percent < 10.0) {
        status = "WARNING";
    }
//const char是说明地址指的N不可更改，不能通过*status = 'X'来改变值
//char * const status = "NORMAL";只能永远存N的地址，此时可以*status改变地址上的值
    printf("Voltage: %.3f V\n", voltage_v);
    printf("Temperature: %.1f C\n", temperature_c);
    printf("SOC: %.1f %%\n", soc_percent);
    printf("Charge cycles: %u\n", cycle_count);
    printf("Status: %s\n", status);//status 这个变量存的值是一个地址（比如 0x1000，指向 "ALARM" 的首字符）。所以这行代码执行时，传给 printf 的实际上就是一个数字——0x1000，而不是字符串本身。
//%s 告诉 printf "这个参数是个字符串地址"，printf 自己跑一个循环，逐字节读，直到遇到 \0
    return 0;
}
