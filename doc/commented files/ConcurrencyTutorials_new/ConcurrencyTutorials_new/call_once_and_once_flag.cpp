#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <thread>
#include <memory>


class some_data{
public:
	void do_something();
};

std::shared_ptr<some_data> resource_ptr;
std::once_flag resource_flag;

void init_resource()
{
	resource_ptr.reset(new some_data);
}


void func()
{
	std::call_once(resource_flag, init_resource);
	resource_ptr->do_something();
}

//int main()
//{
//	system("pause");
//	return 0;
//}