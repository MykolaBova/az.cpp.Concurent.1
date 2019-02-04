#ifndef VIDEO_4_CODE_1
#define VIDEO_4_CODE_1
#include <iostream>
#include <thread>
#include <chrono>

void func_1()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "hello from method \n";
}


void run_code()
{ 
	std::thread thread_1(func_1);
	thread_1.join();

	std::cout << "hello from main thread \n";
}

#endif
