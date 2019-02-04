#ifndef VIDEO_5_CODE_1
#define VIDEO_5_CODE_1

#include <iostream>
#include <thread>
#include <stdexcept>

void func_1()
{
	std::cout << "hello from method \n";
}

void other_operations()
{
	throw std::runtime_error("this is a runtime error");
}

void run_code()
{
	std::thread thread_1(func_1);

	try {
		//do other operations
		other_operations();
		thread_1.join();
	}
	catch (...)
	{
	}
	std::cout << "This is main thread \n";
}








#endif