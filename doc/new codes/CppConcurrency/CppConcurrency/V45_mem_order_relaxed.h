#ifndef VIDEO_45_MEM_ORDER_RELAXED
#define VIDEO_45_MEM_ORDER_RELAXED

#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y()
{
	x.store(true, std::memory_order_relaxed);
	y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
	while (!y.load(std::memory_order_relaxed));
	if (x.load(std::memory_order_relaxed))
	{
		z++;
	}
}

void run_code()
{
	x = false;
	y = false;
	z = 0;

	std::thread writer_thread(write_x_then_y);
	std::thread reader_thread(read_y_then_x);

	writer_thread.join();
	reader_thread.join();

	assert(z != 0);
}

#endif // !VIDEO_45_MEM_ORDER_RELAXED
