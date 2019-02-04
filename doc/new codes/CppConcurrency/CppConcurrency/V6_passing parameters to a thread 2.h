#ifndef VIDEO_6_CODE_2
#define VIDEO_6_CODE_2

#include <iostream>
#include <thread>
#include <chrono>

void func_1(int & x)
{
	while (true)
	{
		std::cout << "Thread_1 x value : " << x << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void run_code()
{
	int x = 9;
	std::cout <<"Main thread current value of X is : "<< x <<std::endl;
	std::thread thread_1(func_1,std::ref(x));
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	
	x = 15;
	std::cout << "Main thread X value changed to : " << x << std::endl;
	thread_1.join();
}
#endif