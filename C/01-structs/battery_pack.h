#ifndef BATTERY_PACK_H
#define BATTERY_PACK_H

#include <stddef.h>

#define MAX_CELLS 16

typedef struct {
    unsigned int id;
    double voltage_v;
    double temperature_c;
    double soc_percent;
} Cell;

typedef struct {
    char name[32];
    size_t cell_count;
    Cell cells[MAX_CELLS];
} BatteryPack;

typedef struct {
    double average_voltage_v;
    double min_voltage_v;
    size_t min_cell_index;
    double max_voltage_v;
    size_t max_cell_index;
    double spread_mv;
} VoltageStats;

int battery_pack_voltage_stats(const BatteryPack *pack, VoltageStats *stats);
int battery_pack_is_balanced(const VoltageStats *stats, double threshold_mv);

#endif
