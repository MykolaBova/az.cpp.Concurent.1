#include <iostream>
#include <thread>
#include <chrono>

void func_1(int & x)
{
	while (true)
	{
		std::cout << x <<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}


//int main()
//{
//	int x = 9;
//	std::thread thread_1(func_1,std::ref(x));
//	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//	x = 15;
//
//	std::cout << "x value has been changed to \n";
//	thread_1.join();
//	system("pause");
//	return 0;
//}