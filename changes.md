# 变更记录

## 0002 — 2026-09-29

### 新增
- `main/mcu_cmsis.h`：MCU 桥接头，仅转发 `eg. #include "py32f0xx.h"`。让上层头文件通过它间接依赖当前 MCU 的 CMSIS，避免写死具体器件头文件。

### 修改
- `irq_lock.hpp`：
  - 改为 `#include "mcu_cmsis.h"`（此前未包含任何 CMSIS 头）。
  - 修复 `__get_PRIMASK()` / `__disable_irq()` / `__set_PRIMASK()` 未声明的问题——这些内建函数定义在 `cmsis_gcc.h`，需经厂商提供的头文件逐级引入。
  - 清理已不再需要的空实现兜底宏注释。
