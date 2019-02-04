#ifndef THREAD_SAFE_QUEUE
#define THREAD_SAFE_QUEUE

#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>

template<typename T>
class thread_safe_queue{
	std::mutex m;
	std::condition_variable cv;
	std::queue<T> queue;

public:
	thread_safe_queue()
	{}

	thread_safe_queue(thread_safe_queue const& other_queue)
	{
		std::lock_guard<std::mutex> lg(other_queue.m);
		queue = other_queue.queue;
	}

	void push(T& value)
	{
		std::lock_guard<std::mutex> lg(m);
		queue.push(value);
		cv.notify_one();
	}

	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lg(m);
		if (queue.empty())
		{
			return std::shared_ptr<T>();
		}
		else
		{
			std::shared_ptr<T> ref(std::make_shared<T>(queue.front()));
				queue.pop();
			return ref;
		}
	}

	bool pop(T& ref)
	{
		std::lock_guard<std::mutex> lg(m);
		if (queue.empty())
		{
			return false;
		}
		else
		{
			ref = queue.front();
			queue.pop();
			return true;
		}
	}

	bool wait_pop(T& ref)
	{
		std::unique_lock<std::mutex> lg(m);
		cv.wait(lg, [this]{
			return !queue.empty();
		});
		ref = queue.front();
		queue.pop();

	}

	std::shared_ptr<T> wait_pop()
	{
		std::unique_lock<std::mutex> lg(m);
		cv.wait(lg, [this]{
			return !queue.empty();
		});
		std::shared_ptr<T> ref(std::make_shared<T>(queue.front()))
			queue.pop();
		return ref;
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lg(m);
		queue.empty();
	}
};

#endif