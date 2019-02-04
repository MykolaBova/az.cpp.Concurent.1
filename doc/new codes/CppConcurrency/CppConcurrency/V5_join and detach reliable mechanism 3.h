#ifndef VIDEO_5_CODE_3
#define VIDEO_5_CODE_3
#include <iostream>
#include <thread>
#include <stdexcept>
#include <chrono>
#include "thread_guard.h"

void func_1()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "hello from method \n";
}

void other_operations()
{
	std::cout << "This is other operation \n";
	throw std::runtime_error("this is a runtime error");
}

void run_code()
{
	std::thread thread_1(func_1);
	thread_guard tg(thread_1);

	//do other operations
	try
	{
		other_operations();
	}
	catch(...)
	{
	}
}
#endif