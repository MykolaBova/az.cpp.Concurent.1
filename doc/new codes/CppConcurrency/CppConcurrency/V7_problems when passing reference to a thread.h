#ifndef VIDEO_7_CODE
#define VIDEO_7_CODE

#include <iostream>
#include <thread>
#include <chrono>

void func_2(int & x)
{
	while (true)
	{
		std::cout << x << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void func_1()
{
	int x = 5;
	std::thread thread_2(func_2, std::ref(x));
	thread_2.detach();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "thread_1 finished execution \n"; 
}


void run_code()
{
	std::thread thread_1(func_1);
	thread_1.join();
}

#endif