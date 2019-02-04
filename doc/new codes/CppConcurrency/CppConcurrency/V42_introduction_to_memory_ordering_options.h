#ifndef VIDEO_42_INTRO_MEMORY_ORDERING_OPTIONS
#define VIDEO_42_INTRO_MEMORY_ORDERING_OPTIONS

#include <iostream>
#include <thread>
#include <atomic>

void run_code()
{
	std::atomic<int> x;

	x.store(5,std::memory_order_seq_cst);

	x.store(10, std::memory_order_release);
	x.load(std::memory_order_acquire);

	int value = 11;
	bool ret_val = x.compare_exchange_weak(value, 13,
		std::memory_order_release, std::memory_order_relaxed);
}



#endif // !VIDEO_42_INTRO_MEMORY_ORDERING_OPTIONS
