#ifndef VIDEO_8_CODE
#define VIDEO_8_CODE
#include <iostream>
#include <thread>

void func_1()
{
	std::cout << "This is a function 1";
}

void func_2()
{
	std::cout << "This is a function 2";
}

void run_code()
{
	std::thread thread_1(func_1);
	
	//try to assigne one thread to another
	//std::thread thread_2 = thread_1;  

	//move one thread form another
	std::thread thread_2 = std::move(thread_1);

	//implicit call to move constructor
	thread_1 = std::thread(func_2);

	std::thread thread_3 = std::move(thread_2);

	//this is wrong
	thread_1 = std::move(thread_3); 
	
	thread_1.join();
	thread_3.join();

}

#endif