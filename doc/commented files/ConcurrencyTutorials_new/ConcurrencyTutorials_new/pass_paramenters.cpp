#include <iostream>
#include <thread>

void func_1(int x, int y)
{
	std::cout << " X + Y = " << x + y << std::endl;
}


//int main()
//{
//	int x = 9;
//	int y = 8;
//
//	std::thread thread_1(func_1,x,y);
//
//	thread_1.join();
//	system("pause");
//	return 0;
//}