#ifndef VIDEO_9_CODE_2
#define VIDEO_9_CODE_2

#include <iostream>
#include <thread>

void run_code()
{
	std::cout << "Allowed max number of parallel threads : " 
		<< std::thread::hardware_concurrency() << std::endl;
}
#endif