# RoboMaster C 板入门练习

基于 RoboMaster C 型开发板和同济大学 SuperPower 战队的 `sp_middleware`，练习 PWM 输出与 FreeRTOS 多任务开发。

## 主要功能

- **呼吸灯**：通过 PWM 调节绿色 LED 的亮度，实现循环渐亮、渐暗。
- **蜂鸣器**：程序启动后短响三声，随后保持静音。
- LED 与蜂鸣器分别运行在独立的 FreeRTOS 任务中。

## 硬件配置

开发板：RoboMaster C 型，主控：STM32F407IGH6。

| 功能 | 引脚 | 定时器通道 |
| --- | --- | --- |
| 蓝色 LED | PH10 | TIM5_CH1 |
| 绿色 LED | PH11 | TIM5_CH2 |
| 红色 LED | PH12 | TIM5_CH3 |
| 蜂鸣器 | PD14 | TIM4_CH3 |

## 开发环境

- STM32CubeMX：配置外设及 FreeRTOS，生成 CMake 工程。
- VS Code + STM32CubeCLT：编辑与编译代码。
- OpenOCD + Cortex-Debug：烧录与调试。
- [sp_middleware](https://github.com/TongjiSuperPower/sp_middleware)：LED 与蜂鸣器驱动，以 Git 子模块方式引入。

环境配置参考：[战队 STM32 开发环境说明](https://github.com/TongjiSuperPower/stm32_dev_env)。

## 使用方法

1. 克隆工程后，在工程根目录执行以下命令，获取中间件：

   ```bash
   git submodule update --init --recursive
   ```

2. 使用 VS Code 打开工程根目录，选择 CMake 的 `Debug` 配置。
3. 按照实际下载器配置 `openocd.cfg`，连接 C 板后编译、烧录。
4. 复位开发板，观察绿色呼吸灯与蜂鸣器三声效果。

应用逻辑位于 `applications/led_task.cpp` 和 `applications/buzzer_task.cpp`；任务入口分别为 `led_task` 和 `buzzer_task`，在 CubeMX 中使用 `As external` 方式配置。
