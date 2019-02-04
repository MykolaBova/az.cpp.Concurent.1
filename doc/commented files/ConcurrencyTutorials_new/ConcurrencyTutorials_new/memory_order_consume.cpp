#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <assert.h>


struct X{
	int i;
	std::string s;
};

std::atomic<X*>p;
std::atomic<int> a;

void create_x()
{
	X* x = new X;
	x->i = 42;
	x->s = "hello";

	a.store(20, std::memory_order_relaxed);
	p.store(x, std::memory_order_release);
}

void use_x()
{
	X* x;
	while (!(x = p.load(std::memory_order_consume)));
	assert(x->i == 42);
	assert(x->s == "hello");
	assert(a.load(std::memory_order_relaxed) == 20);
}

//int main()
//{
//	std::thread create_thread(create_x);
//	std::thread use_thread(use_x);
//
//	create_thread.join();
//
//	use_thread.join();
//
//	system("pause");
//	return 0;
//}