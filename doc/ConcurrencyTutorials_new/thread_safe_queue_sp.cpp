//#ifndef THREAD_SAFE_QUEUE_SP
//#define THREAD_SAFE_QUEUE_SP
//
//#include <iostream>
//#include <mutex>
//#include <queue>
//#include <memory>
//#include <condition_variable>
//#include <thread>
//
//template<typename T>
//class thread_safe_queue_sp{
//	std::mutex m;
//	std::condition_variable cv;
//	std::queue<std::shared_ptr<T>> queue;
//
//public:
//	thread_safe_queue_sp()
//	{}
//
//	thread_safe_queue(thread_safe_queue_sp const& other_queue)
//	{
//		std::lock_guard<std::mutex> lg(other_queue.m);
//		queue = other_queue.queue;
//	}
//
//	void push(T& value)
//	{
//		std::shared_ptr<T> data(std::make_shared<T>(std::move(value)));
//		std::lock_guard<std::mutex> lg(m);
//		queue.push(data);
//		cv.notify_one();
//	}
//
//	std::shared_ptr<T> pop()
//	{
//		std::lock_guard<std::mutex> lg(m);
//		if (queue.empty())
//		{
//			return std::shared_ptr<T>();
//		}
//		else
//		{
//			std::shared_ptr<T> ref = queue.front();
//				queue.pop();
//			return ref;
//		}
//	}
//
//	bool pop(T& ref)
//	{
//		std::lock_guard<std::mutex> lg(m);
//		if (queue.empty())
//		{
//			return false;
//		}
//		else
//		{
//			ref = std::move(*(queue.front()));
//			queue.pop();
//			return true;
//		}
//	}
//
//	bool wait_pop(T& ref)
//	{
//		std::unique_lock<std::mutex> lg(m);
//		cv.wait(lg, [this]{
//			return !queue.empty();
//		});
//		ref = std::move(*(queue.front()));
//		queue.pop();
//
//	}
//
//	std::shared_ptr<T> wait_pop()
//	{
//		std::unique_lock<std::mutex> lg(m);
//		cv.wait(lg, [this]{
//			return !queue.empty();
//		});
//		std::shared_ptr<T> ref = queue.front();
//		queue.pop();
//		return ref;
//	}
//
//	bool empty()
//	{
//		std::lock_guard<std::mutex> lg(m);
//		queue.empty();
//	}
//};
//
//#endif