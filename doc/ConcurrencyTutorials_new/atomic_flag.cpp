#include <iostream>
#include <thread>
#include <atomic>


int main()
{
	//std::atomic_flag flag1= true;
	std::atomic_flag flag2 = ATOMIC_FLAG_INIT;

	//set the flag value to true and return previous value
	std::cout << "1.previous flag value  : " << flag2.test_and_set() << std::endl;
	std::cout << "2.previous flag value  : " << flag2.test_and_set() << std::endl;
	//clear the flag value
	flag2.clear();
	std::cout << "3.previous flag value  : " << flag2.test_and_set() << std::endl;


	system("pause");
	return 0;
}  