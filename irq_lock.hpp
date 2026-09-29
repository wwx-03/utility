#pragma once

#ifndef __disable_irq
	#define __disable_irq()
#endif /* __disable_irq */

#ifndef __enable_irq
	#define __enable_irq()
#endif /* __enable_irq */

#ifndef __get_PRIMASK
    #define __get_PRIMASK() 0u
#endif /* __get_PRIMASK */

#ifndef __set_PRIMASK
    #define __set_PRIMASK(x) do { (void)(x); } while (0)
#endif /* __set_PRIMASK */

class irq_lock {
public:
	irq_lock() { primask_ = __get_PRIMASK(); __disable_irq(); }
	~irq_lock() { __set_PRIMASK(primask_); }
	irq_lock(const irq_lock &) = delete;
	irq_lock &operator=(const irq_lock &) = delete;
private:
	uint32_t primask_;
};
