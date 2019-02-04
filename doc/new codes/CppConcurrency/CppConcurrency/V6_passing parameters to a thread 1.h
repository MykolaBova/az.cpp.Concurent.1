#ifndef VIDEO_6_CODE_1
#define VIDEO_6_CODE_1

#include <iostream>
#include <thread>

void func_1(int x, int y)
{
	std::cout << " X + Y = " << x + y << std::endl;
}

void run_code()
{
	int p = 9;
	int q = 8;

	std::thread thread_1(func_1,p,q);

	thread_1.join();
}

#endif
