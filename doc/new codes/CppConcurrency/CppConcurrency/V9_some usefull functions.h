#ifndef VIDEO_9_CODE_1
#define VIDEO_9_CODE_1

#include <iostream>
#include <thread>
#include <chrono>

void func_1()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "new  thread id : " << std::this_thread::get_id() << std::endl;
}

void run_code()
{
	std::thread thread_1(func_1);	
	
	std::cout << "thread_1 id before joining : " << thread_1.get_id() << std::endl;
	thread_1.join();

	std::thread thread_2;
	
	std::cout << "default consturcted thread id : " << thread_2.get_id() << std::endl;
	std::cout << "thread_1 id after joining : " << thread_1.get_id() << std::endl;
	std::cout << "Main thread id : " << std::this_thread::get_id() << std::endl;

	std::cout << "\n\nAllowed max number of parallel threads : " 
		<< std::thread::hardware_concurrency() << std::endl;
}

#endif
