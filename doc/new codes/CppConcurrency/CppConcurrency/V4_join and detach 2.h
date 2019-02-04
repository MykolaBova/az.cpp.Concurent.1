#ifndef VIDEO_4_CODE_2
#define VIDEO_4_CODE_2

#include <iostream>
#include <thread>
#include <chrono>

void func_1()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "hello from func_1 \n";
}

void run_code()
{
	std::thread thread_1(func_1);
	thread_1.detach();

	std::cout << "hello from main thread \n";
}

#endif