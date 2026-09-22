#include <stdio.h>

static double calculate_average(const double values[], int count)
{
    if (count <= 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += values[i];
    }
    return sum / count;
}

static int find_min_index(const double values[], int count)
{
    if (count <= 0) {
        return -1;
    }

    int min_index = 0;
    for (int i = 1; i < count; ++i) {
        if (values[i] < values[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

static int count_below(const double values[], int count, double limit)
{
    int result = 0;
    for (int i = 0; i < count; ++i) {
        if (values[i] < limit) {
            ++result;
        }
    }
    return result;
}

static const char *voltage_level(double voltage)
{
    if (voltage >= 4.15) {
        return "high";
    }
    if (voltage <= 3.00) {
        return "low";
    }
    return "normal";
}

int main(void)
{
    const double samples[] = {4.16, 4.08, 4.01, 3.97, 3.02, 2.98};
    const int count = (int)(sizeof(samples) / sizeof(samples[0]));
    const int min_index = find_min_index(samples, count);

    printf("Average: %.3f V\n", calculate_average(samples, count));
    printf("Minimum: %.3f V at index %d\n", samples[min_index], min_index);
    printf("Below 3.00 V: %d samples\n", count_below(samples, count, 3.00));

    for (int i = 0; i < count; ++i) {
        printf("sample[%d] = %.3f V (%s)\n",
               i, samples[i], voltage_level(samples[i]));
    }

    return 0;
}
