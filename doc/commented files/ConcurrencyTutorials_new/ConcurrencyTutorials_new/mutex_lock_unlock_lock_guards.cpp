#include <iostream>
#include <mutex>
#include <list>
#include <thread>

std::list<int> my_list;
std::mutex m;

void add_to_list(int const & x)
{
	std::lock_guard<std::mutex> lg(m);
	my_list.push_back(x);
}

void size()
{
	std::lock_guard<std::mutex> lg(m);
	int size = my_list.size();
	std::cout << "size of the list is : " << size << std::endl;
}

//int main()
//{
//	std::thread thread_1(add_to_list, 4);
//	std::thread thread_2(add_to_list, 11);
//
//	thread_1.join();
//	thread_2.join();
//	system("pause");
//	return 0;
//}