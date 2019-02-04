#include <iostream>
#include <thread>

void func_1()
{
	std::cout << "hello from method \n";
}


int main()
{
	std::thread thread_1(func_1);

	if (thread_1.joinable())
		std::cout << "this is joinable thread \n";

	thread_1.join();

	if (thread_1.joinable())
	{
		std::cout << "this is joinable thread \n";
	}
	else
	{
		std::cout << "this is not a joinable thread \n";
	}

	std::cout << "hello from main \n";

	system("pause");
	return 0;
}