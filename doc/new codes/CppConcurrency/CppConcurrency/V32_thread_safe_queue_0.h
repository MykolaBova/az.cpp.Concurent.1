#ifndef V32_THREAD_SAFE_QUEUE_0
#define V32_THREAD_SAFE_QUEUE_0

#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>

template<typename T>
class sequential_queue {

	struct node
	{
		T data;
		std::unique_ptr<node> next;

		node(T _data) : data(std::move(_data))
		{
		}
	};

	std::unique_ptr<node> head;
	node* tail;

public:
	void push(T value)
	{
		std::unique_ptr<node> new_node(new node(std::move(value)));
		node * const new_tail = new_node.get();

		if (tail)
		{
			tail->next = std::move(new_node);
		}
		else
		{
			head = std::move(new_node);
		}
		tail = new_tail;
	}

	std::shared_ptr<T> pop()
	{
		if (!head)
		{
			return std::shared_ptr<T>();
		}
		std::shared_ptr<T> const res(std::make_shared<T>(std::move(head->data)));
		std::unique_ptr<node> const old_head = std::move(head);
		head = std::move(old_head->next);
		return res;
	}
};


#endif // !V32_THREAD_SAFE_QUEUE_1

