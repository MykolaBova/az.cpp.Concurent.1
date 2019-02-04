#ifndef VIDEO_37_ATOMIC_BOOL_2
#define VIDEO_37_ATOMIC_BOOL_2

#include <iostream>
#include <thread>
#include <atomic>

void run_code()
{
	std::atomic<bool> x(false);
	std::cout << "atomic boolean is implemented lock free - " 
		<< (x.is_lock_free() ? "yes" : "no") << std::endl;

	std::atomic<bool> y(true);

	//store operations
	x.store(false);
	x.store(y);

	//load operations
	std::cout << "value of the atomic bool y - "<< y.load() << std::endl;

	//exchange operatrion
	bool z = x.exchange(false);

	std::cout << "current value of atomic bool x - " << x.load() << std::endl;
	std::cout << "previous value of atomic bool x - " << z << std::endl;

	std::cout << std::endl;
}

#endif