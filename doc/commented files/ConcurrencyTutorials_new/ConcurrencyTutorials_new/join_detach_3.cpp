#include <iostream>
#include <thread>
#include <chrono>

void func_1()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "hello from method \n";
}


//int main()
//{
//	std::thread thread_1(func_1);
//
//	thread_1.detach();
//
//	std::cout << "hello from main \n";
//
//	system("pause");
//	return 0;
//}