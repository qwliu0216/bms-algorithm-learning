#include <stdio.h>

int main(void)
{
    const double voltage_samples[] = {
        4.012, 4.005, 3.998, 3.978, 3.965, 3.972,
        3.981, 3.990, 3.984, 3.976, 3.968, 3.971
    };
    const int sample_count = (int)(sizeof(voltage_samples) / sizeof(voltage_samples[0]));
    const double low_voltage_limit = 3.980;
//为什么最终要的是有符号的 int，而不是直接用 size_t
//这里有个更深层的工程原因，尤其和 BMS/嵌入式代码风格有关：
//如果 sample_count 保持 size_t（无符号）类型，后面万一写出这样的代码：
//for (int i = sample_count - 1; i >= 0; i--) {   // 想从后往前遍历
//一旦 sample_count 是无符号类型，sample_count - 1 在 sample_count 恰好等于 0 时会发生无符号数下溢（不会变成 -1，而是变成一个巨大的正数，比如 4294967295），导致循环条件永远成立，出现严重 bug、甚至数组越界访问。
    double sum = 0.0;
    double minimum = voltage_samples[0];
    double maximum = voltage_samples[0];
    int low_run = 0;
    int longest_low_run = 0;

    for (int i = 0; i < sample_count; ++i) {
        const double voltage = voltage_samples[i];
        sum += voltage;

        if (voltage < minimum) {
            minimum = voltage;
        }
        if (voltage > maximum) {
            maximum = voltage;
        }

        if (voltage < low_voltage_limit) {
            ++low_run;
            if (low_run > longest_low_run) {
                longest_low_run = low_run;//历史上出现过的最长连续次数"（记录峰值）
            }
        } else {
            low_run = 0;//当前正在连续低于阈值的次数
        }
    }

    printf("Samples: %d\n", sample_count);
    printf("Average: %.3f V\n", sum / sample_count);
    printf("Minimum: %.3f V\n", minimum);
    printf("Maximum: %.3f V\n", maximum);
    printf("Spread: %.1f mV\n", (maximum - minimum) * 1000.0);
    printf("Longest low-voltage run: %d samples\n", longest_low_run);

    return 0;
}
