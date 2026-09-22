#include "battery_pack.h"

int battery_pack_voltage_stats(const BatteryPack *pack, VoltageStats *stats)
{
    if (pack == NULL || stats == NULL || pack->cell_count == 0 ||
        pack->cell_count > MAX_CELLS) {
        return 0;
    }

    double sum = 0.0;
    stats->min_voltage_v = pack->cells[0].voltage_v;
    stats->max_voltage_v = pack->cells[0].voltage_v;
    stats->min_cell_index = 0;
    stats->max_cell_index = 0;

    for (size_t i = 0; i < pack->cell_count; ++i) {
        const double voltage = pack->cells[i].voltage_v;
        sum += voltage;

        if (voltage < stats->min_voltage_v) {
            stats->min_voltage_v = voltage;
            stats->min_cell_index = i;
        }

        if (voltage > stats->max_voltage_v) {
            stats->max_voltage_v = voltage;
            stats->max_cell_index = i;
        }
    }

    stats->average_voltage_v = sum / (double)pack->cell_count;
    stats->spread_mv = (stats->max_voltage_v - stats->min_voltage_v) * 1000.0;
    return 1;
}

int battery_pack_is_balanced(const VoltageStats *stats, double threshold_mv)
{
    if (stats == NULL || threshold_mv < 0.0) {
        return 0;
    }

    return stats->spread_mv <= threshold_mv;
}
