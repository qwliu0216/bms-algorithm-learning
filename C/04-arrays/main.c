#include <stdio.h>

#define SAMPLE_COUNT 10

int main(void)
{
    double voltage[SAMPLE_COUNT] = {
        4.010, 4.008, 4.006, 4.004, 3.998,
        3.970, 3.972, 3.971, 3.969, 3.968
    };
    const double sudden_change_limit = 0.020;
    int sudden_change_count = 0;

    printf("Voltage window:\n");
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        printf("  [%d] %.3f V\n", i, voltage[i]);
    }

    printf("Adjacent changes:\n");
    for (int i = 1; i < SAMPLE_COUNT; ++i) {
        const double change = voltage[i] - voltage[i - 1];
        printf("  %d -> %d: %+.3f V\n", i - 1, i, change);

        if (change < -sudden_change_limit || change > sudden_change_limit) {
            ++sudden_change_count;
        }
    }

    double first_half_sum = 0.0;
    double second_half_sum = 0.0;
    for (int i = 0; i < SAMPLE_COUNT / 2; ++i) {
        first_half_sum += voltage[i];
        second_half_sum += voltage[i + SAMPLE_COUNT / 2];
    }

    printf("Sudden changes: %d\n", sudden_change_count);
    printf("First-half average: %.3f V\n", first_half_sum / (SAMPLE_COUNT / 2));
    printf("Second-half average: %.3f V\n", second_half_sum / (SAMPLE_COUNT / 2));

    return 0;
}
