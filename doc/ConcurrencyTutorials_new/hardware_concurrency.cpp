#include <iostream>
#include <thread>


int main()
{
	std::cout << "Allowed max number of parallel threads : " << std::thread::hardware_concurrency() << std::endl;
	system("pause");
	return 0;
}