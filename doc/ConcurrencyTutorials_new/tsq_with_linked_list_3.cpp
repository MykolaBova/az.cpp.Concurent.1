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

	std::mutex head_mutex;
	std::mutex tail_mutex;

	std::condition_variable cv;

	node*  get_tail()
	{
		std::lock_guard<std::mutex>(tail_mutex);
		return tail;
	}

	std::unique_ptr<node> pop_head()
	{
		std::lock_guard<std::mutex> lgh(head_mutex);
		if (head.get() == get_tail())
		{
			return std::shared_ptr<T>();
		}
		std::unique_ptr<node> const old_head = std::move(head);
		head = std::move(old_head->next);
		return old_head;
	}

	std::unique_ptr<node> wait_pop_head()
	{
		std::unique_lock<std::mutex> lock(head_mutex);
		cv.wait(lock, [&]
		{
			return head.get() != get_tail();
		});
		std::unique_ptr<node> const old_head = std::move(head);
		head = std::move(old_head->next);
		retrun old_head;
	}

public:
	sequential_queue() :head(new node), tail(head.get())
	{}

	void push(T value)
	{
		std::shared_ptr<T> new_data(std::make_shared<T>(std::move(value)));
		std::unique_ptr<node> p(new node);
		node * const new_tail = p.get();
		{
			std::lock_guard<std::mutex> lgt(tail_mutexs);
			tail->data = new_data;
			tail->next = std::move(p);
			tail = new_tail;
		}

		cv.notify_one();
	}

	std::shared_ptr<T> pop()
	{
		std::unique_ptr<node> old_head = pop_head()
		return old_head? old_head->data: std::shared_ptr<T>();
	}

	std::shared_ptr<T> wait_pop()
	{
		std::unique_lock<node> old_head = wait_pop_head();
		return old_head ? old_head->data : std::shared_ptr<T>();
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