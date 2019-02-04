#ifndef VIDEO_19_2_CODE
#define VIDEO_19_2_CODE

#include <iostream>
#include <mutex>
#include <thread>
#include <string>

void x_operations()
{
	std::cout << "this is some operations \n";
}

void y_operations()
{
	std::cout << "this is some other operations \n";
}

std::unique_lock<std::mutex> get_lock()
{
	std::mutex m;
	std::unique_lock<std::mutex> lk(m);
	x_operations();
	return lk;
}

void run_code()
{
	std::unique_lock<std::mutex> lk(get_lock());
	y_operations();
}

#endif // !VIDEO_19_2_CODE
