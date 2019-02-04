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
		std::shared_ptr<T> data;
		std::unique_ptr<node> next;

		node(T _data) : data(std::move(_data))
		{
		}
	};

	std::unique_ptr<node> head;
	node* tail;


public:
	sequential_queue() :head(new node), tail(head.get())
	{}

	void push(T value)
	{
		//change current dummy nodes data value
		std::shared_ptr<T> new_data(std::make_shared<T>(std::move(value)));
		tail->data = new_data;
		
		//add new dummy node to tail
		std::unique_ptr<node> p(new node);
		node * const new_tail = p.get();
		tail->next = std::move(p);
		tail = new_tail;
	}


	std::shared_ptr<T> pop()
	{
		if (head.get() == tail)
		{
			return std::shared_ptr<T>();
		}
		std::shared_ptr<T> const res(head->data);
		std::unique_ptr<node> const old_head = std::move(head);
		head = std::move(old_head->next);
		return res;
	}
};


//int main()
//{
//	sequential_queue<int> queue;
//	queue.push(3);
//	queue.push(4);
//	queue.push(7);
//	queue.push(5);
//	queue.pop();
//	system("pause");
//	return 0;
//}