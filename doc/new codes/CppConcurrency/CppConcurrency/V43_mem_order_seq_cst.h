#ifndef VIDEO_43_MEM_ORDER_SEQ_CST
#define VIDEO_43_MEM_ORDER_SEQ_CST

#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x()
{
	x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
	y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
	// loop until x is true
	while (!x.load(std::memory_order_seq_cst));

	//check wether y is true
	if (y.load(std::memory_order_seq_cst))
	{
		z++;
	}
}

void read_y_then_x()
{
	// loop until y is true
	while (!y.load(std::memory_order_seq_cst));

	//check wether x is true
	if (x.load(std::memory_order_seq_cst))
	{
		z++;
	}
}

void run_code()
{
	x = false;
	y = false;
	z = 0;

	std::thread thread_a(write_x);
	std::thread thread_b(write_y);
	std::thread thread_c(read_x_then_y);
	std::thread thread_d(read_y_then_x);

	thread_a.join();
	thread_b.join();
	thread_c.join();
	thread_d.join();

	assert(z != 0);
}

#endif // !VIDEO_43_MEM_ORDER_SEQ_CST
