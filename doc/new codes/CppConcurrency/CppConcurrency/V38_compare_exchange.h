#ifndef VIDEO_38_COMPARE_EXCHANGE
#define VIDEO_38_COMPARE_EXCHANGE

#include <iostream>
#include <thread>
#include <atomic>

void run_code()
{
	std::atomic<int> x(20);
	
	int expected_value = 10;
	std::cout << "previous expected_value - " << expected_value << std::endl;
	bool return_val = x.compare_exchange_weak(expected_value, 6);
	
	std::cout << "operation successful    - " << (return_val ? "yes" : "no") << std::endl;
	std::cout << "current expected_value  - " << expected_value << std::endl;
	std::cout << "current x               - " << x.load() << std::endl;
}

#endif
