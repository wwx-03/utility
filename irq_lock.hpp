#pragma once

#include "mcu_cmsis.h" // 桥接头：由工程提供，包含具体 MCU 的 CMSIS

class irq_lock {
public:
	irq_lock() { primask_ = __get_PRIMASK(); __disable_irq(); }
	~irq_lock() { __set_PRIMASK(primask_); }
	irq_lock(const irq_lock &) = delete;
	irq_lock &operator=(const irq_lock &) = delete;
private:
	uint32_t primask_;
};
