# C 练习 01：结构体与电芯一致性统计

这个练习把 C 结构体放进一个小型 BMS 场景中：

- `Cell` 表示单体电芯的编号、电压、温度和 SOC。
- `BatteryPack` 表示一个电池包及其电芯数组。
- `VoltageStats` 保存电压平均值、最大值、最小值和压差。
- `battery_pack_voltage_stats()` 负责统计。
- `battery_pack_is_balanced()` 用压差阈值做一个最简单的一致性判断。

## 编译运行

在本目录打开终端：

```text
gcc -std=c11 -Wall -Wextra -pedantic main.c battery_pack.c -o battery_demo
./battery_demo
```

Windows 如果使用 MinGW，运行文件通常是 `battery_demo.exe`。

## 你需要自己完成的改进

1. 增加最高温度、最低温度和温差统计。
2. 增加一个函数，计算所有电芯 SOC 的平均值。
3. 把 30 mV 阈值从 `main.c` 的硬编码改为配置项。
4. 构造一个空电池包和超过 `MAX_CELLS` 的电池包，观察错误处理。
5. 将示例数据改成 8 节电芯，并说明哪一节最需要关注。

完成后再进入指针、文件读写和动态内存，不要急着直接写 EKF。
