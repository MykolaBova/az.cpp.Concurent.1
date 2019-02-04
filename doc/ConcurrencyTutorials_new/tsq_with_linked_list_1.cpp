#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>

template<typename T>
class sequential_queue{

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
	std::mutex head_mutex;
	std::mutex tail_mutex;


public:
	void push(T value)
	{
		std::unique_ptr<node> new_node(new node(std::move(value)));
		node * const new_tail = new_node.get();

		std::lock_guard<std::mutex> tlg(tail_mutex);
		if (tail)
		{
			tail->next = std::move(new_node);
		}
		else
		{
			std::lock_guard<std::mutex> hlg(head_mutex);
			head = std::move(new_node);
		}
		tail = new_tail;
	}

	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> hlg(head_mutex);
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


int main()
{
	sequential_queue<int> queue;
	queue.push(3);
	queue.push(4);
	queue.push(7);
	queue.push(5);
	queue.pop();
	system("pause");
	return 0;
}