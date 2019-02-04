#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>
#include "thred_guard.h"

void func_1()
{
	std::cout << "hello from method \n";
}


void other_operations()
{
	throw std::runtime_error("this is a runtime error");
}

int main()
{
	std::thread thread_1(func_1);
	thread_guard tg(thread_1);

	//do other operations
	other_operations();

	system("pause");
	return 0;
}