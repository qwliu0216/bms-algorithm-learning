#include <stdbool.h>
#include <stdio.h>

static void clamp_values(double *values, int count, double lower, double upper)
{
    for (double *current = values; current < values + count; ++current) {
        if (*current < lower) {
            *current = lower;
        } else if (*current > upper) {
            *current = upper;
        }
    }
}

static bool find_first_below(const double *values, int count,
                             double limit, int *result_index)
{
    for (int i = 0; i < count; ++i) {
        if (values[i] < limit) {
            *result_index = i;
            return true;
        }
    }
    return false;
}

static void find_min_max(const double *values, int count,
                         double *minimum, double *maximum)
{
    *minimum = values[0];
    *maximum = values[0];

    for (int i = 1; i < count; ++i) {
        if (values[i] < *minimum) {
            *minimum = values[i];
        }
        if (values[i] > *maximum) {
            *maximum = values[i];
        }
    }
}

int main(void)
{
    double voltage[] = {4.25, 4.11, 3.98, 2.85, 4.32};
    const int count = (int)(sizeof(voltage) / sizeof(voltage[0]));
    double minimum = 0.0;
    double maximum = 0.0;
    int first_low_index = -1;

    clamp_values(voltage, count, 3.00, 4.20);
    find_min_max(voltage, count, &minimum, &maximum);
    const bool found = find_first_below(voltage, count, 3.10, &first_low_index);

    printf("Clamped voltages:\n");
    for (const double *current = voltage; current < voltage + count; ++current) {
        printf("  %.3f V\n", *current);
    }
    printf("Minimum: %.3f V\n", minimum);
    printf("Maximum: %.3f V\n", maximum);
    printf("First value below 3.10 V: %s", found ? "yes" : "no");
    if (found) {
        printf(" (index %d)", first_low_index);
    }
    printf("\n");

    return 0;
}
