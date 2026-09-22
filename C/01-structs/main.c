#include <stdio.h>

#include "battery_pack.h"

int main(void)
{
    BatteryPack pack = {
        .name = "demo-pack-4s",
        .cell_count = 4,
        .cells = {
            { .id = 1, .voltage_v = 4.012, .temperature_c = 25.1, .soc_percent = 82.0 },
            { .id = 2, .voltage_v = 4.005, .temperature_c = 25.4, .soc_percent = 81.5 },
            { .id = 3, .voltage_v = 3.978, .temperature_c = 25.2, .soc_percent = 80.8 },
            { .id = 4, .voltage_v = 4.001, .temperature_c = 25.0, .soc_percent = 81.2 }
        }
    };
    VoltageStats stats;

    if (!battery_pack_voltage_stats(&pack, &stats)) {
        fprintf(stderr, "Invalid battery pack data.\n");
        return 1;
    }

    printf("Pack: %s\n", pack.name);
    printf("Cells: %zu\n", pack.cell_count);
    printf("Average voltage: %.3f V\n", stats.average_voltage_v);
    printf("Minimum voltage: %.3f V (cell %u)\n",
           stats.min_voltage_v, pack.cells[stats.min_cell_index].id);
    printf("Maximum voltage: %.3f V (cell %u)\n",
           stats.max_voltage_v, pack.cells[stats.max_cell_index].id);
    printf("Voltage spread: %.1f mV\n", stats.spread_mv);
    printf("Balance status (threshold 30 mV): %s\n",
           battery_pack_is_balanced(&stats, 30.0) ? "OK" : "CHECK");

    return 0;
}
