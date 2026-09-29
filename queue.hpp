#pragma once

#include <stddef.h>
#include <stdint.h>

#include "irq_lock.hpp"

template <typename T, size_t N>
class queue {
public:
	bool push(const T &src) {
		irq_lock lock;
		if (num_ >= N) return false;
		queue_[(head_ + num_) % N] = src;
		++num_;
		return true;
	}

	bool pop(T &dest) {
		irq_lock lock;
		if (num_ == 0) return false;
		dest = queue_[head_];
		head_ = (head_ + 1) % N;
		--num_;
		return true;
	}

	bool empty() const { irq_lock lock; return num_ == 0; }

	bool full() const { irq_lock lock; return num_ >= N; }

	size_t size() const { irq_lock lock; return num_; }

	void clear() { irq_lock lock; head_ = 0; num_ = 0; }

private:
	T queue_[N] = {};
	volatile size_t num_ = 0;
	volatile size_t head_ = 0;
};
