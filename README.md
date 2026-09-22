# BMS 算法分析师一年学习仓库

这个仓库用于记录从 C 语言基础，到电池模型、参数辨识、SOC 估计，再到嵌入式 CAN-BMS 的完整学习过程。每个阶段都应该留下：代码、输入数据、运行结果、问题记录和一次可复现的提交。

## 目录

```text
master-plan/
├── C/                         C 语言与嵌入式基础
├── Python/                    数据处理、绘图、验证算法
├── MATLAB/                    电池模型与算法快速验证
├── DSP/                       数字信号处理基础
├── BMS/
│   ├── battery-model/         等效电路模型
│   ├── parameter-identification/ 参数辨识
│   └── EKF-SOC/               EKF 与 SOC 估计
├── embedded/CAN-BMS/          MCU、CAN、任务与故障处理
└── FPGA/DSP/                  FPGA 上的 DSP 尝试
```

## 推荐学习顺序

1. `C/`：语法、函数、数组、指针、结构体、文件、模块化和基础调试。
2. `Python/`：读取实验数据、画曲线、计算误差、自动生成报告。
3. `MATLAB/`：建立一阶 RC 等效电路，理解电流、电压、SOC 的关系。
4. `DSP/`：采样、滤波、噪声、离散化和频域基础。
5. `BMS/battery-model/`：Thevenin 一阶模型、OCV-SOC 曲线和库仑计量。
6. `BMS/parameter-identification/`：用实验数据辨识内阻和 RC 参数。
7. `BMS/EKF-SOC/`：先实现普通 EKF，再移植成清晰的 C 模块。
8. `embedded/CAN-BMS/`：把算法接入采样、周期任务、CAN 报文和故障状态机。
9. `FPGA/DSP/`：在真正需要并行计算后，再学习定点化和硬件实现。

## 每个练习的完成标准

- 有一个清楚的 `README.md`，说明输入、输出、公式和运行方式。
- 能够一条命令编译或运行。
- 至少准备一组正常数据和一组异常数据。
- 记录一个可量化结果，例如最大误差、压差、运行时间或滤波效果。
- 完成后提交一次 Git commit，提交信息说明“做了什么”，例如 `C: add pack voltage statistics`。

## Git 初始化

如果这个目录还没有 Git 仓库，可以在根目录执行：

```text
git init
git add .
git commit -m "init BMS algorithm learning roadmap"
```

之后再在 GitHub 或 Gitee 创建同名空仓库，并按平台提示添加远程地址、推送 `main` 分支。
```text
cd "C:\Users\aimer\Documents\GitHub\bms-algorithm-learning"
git add -A     //把所有新增、修改和删除的文件加入本次提交范围。
git commit -m "Update learning content" //把刚才准备好的文件保存成一个本地版本。引号里的文字是本次版本说明
git push origin main
只更新某个文件时，先确保没有其他文件处于暂存状态：git restore --staged .只会取消暂存，不会删除你对文件做的修改。
git add -- "study-log/2026.9.22.md"只添加某个文件
```
