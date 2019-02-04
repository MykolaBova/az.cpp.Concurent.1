#include <iostream>
#include <thread>
#include <atomic>


int main()
{
	std::atomic<int> x;

	x.store(5);

	x.store(10, std::memory_order_release);
	x.load(std::memory_order_acquire);

	int value = 11;
	bool ret_val = x.compare_exchange_weak(value, 13, std::memory_order_release, std::memory_order_relaxed);

	system("pause");
	return 0;
}