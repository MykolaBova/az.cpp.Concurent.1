#include <iostream>
#include <atomic>
#include <thread>
#include <queue>
#include <chrono>


std::atomic<int> count;
std::queue<int> data_queue;
int max_count = 20;

void writer_queue()
{
	for (int i = 0; i < 20; i++)
	{
		data_queue.push(i);
	}

	count.store(20, std::memory_order_release);
}

void reader_queue()
{
	while (true)
	{
		int item_index = 0;
		if (!(item_index = count.fetch_sub(1, std::memory_order_acquire)<=0))
		{
			//wait for items.
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			continue;
		}
		//process the item
	}
}


//int main()
//{
//	std::thread writer_thread(writer_queue);
//	std::thread reader_thread1(reader_queue);
//	std::thread reader_thread2(reader_queue);
//
//	writer_thread.join();
//	reader_thread1.join();
//	reader_thread2.join();
//
//	system("pause");
//	return 0;
//}
