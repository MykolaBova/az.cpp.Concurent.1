#ifndef VIDEO_30_2_CODE
#define VIDEO_30_2_CODE

#include <iostream>       
#include <thread>         
#include <future>         
#include <stdexcept>   


void print_result(std::shared_future<int>& fut)
{
	std::cout << fut.get() << "  - valid future \n";
}

void run_code()
{
	std::promise<int> prom;
	std::shared_future<int> fut(prom.get_future());

	std::thread th1(print_result, std::ref(fut));
	std::thread th2(print_result, std::ref(fut));

	prom.set_value(5);

	th1.join();
	th2.join();
}

#endif // !VIDEO_30_2_CODE
