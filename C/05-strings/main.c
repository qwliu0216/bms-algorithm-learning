#include <stdio.h>
#include <string.h>

int main(void)
{
    char cell_labels[4][16] = {
        "CELL_01", "CELL_02", "CELL_03", "CELL_04"
    };
    const char target[] = "CELL_03";
    int target_index = -1;
    size_t total_label_length = 0U;

    for (int i = 0; i < 4; ++i) {
        total_label_length += strlen(cell_labels[i]);
        if (strcmp(cell_labels[i], target) == 0) {
            target_index = i;
        }
    }

    char report[64];
    const int written = snprintf(report, sizeof(report),
                                 "target=%s,index=%d", target, target_index);

    printf("Target index: %d\n", target_index);
    printf("Total label characters: %zu\n", total_label_length);
    printf("Report: %s\n", report);

    if (written < 0 || (size_t)written >= sizeof(report)) {
        printf("Warning: report was truncated.\n");
    }

    return target_index >= 0 ? 0 : 1;
}
