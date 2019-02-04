#include <iostream>
#include <mutex>
#include <stack>
#include <thread>


template<typename T>
class trivial_thread_safe_stack{
	std::stack<T> stk;
	std::mutex m;

	struct node{
		T data;
		node * next;

	};

	node * head;

public:

	T combine_pop_top()
	{
		node * old_head = head;
		head = old_head->next;
		T value = old_head->data;
		delete old_head;
		return value;
	}
};




trivial_thread_safe_stack<int> stk;

int main()
{
	system("pause");
	return 0;
}
