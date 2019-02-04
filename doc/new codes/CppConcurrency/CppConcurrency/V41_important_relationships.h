#ifndef VIDEO_41_IMPORTANT_RELATIONSHIPS
#define VIDEO_41_IMPORTANT_RELATIONSHIPS

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <chrono>

std::atomic<bool> data_ready = false;
std::vector<int> data_vector;

void reader_func()
{
	while (!data_ready)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << data_vector[0] << std::endl;
}

void writer_func()
{
	data_vector.push_back(3);
	data_ready.store(true);
}


void run_code()
{
	std::thread reader_thread(reader_func);
	std::thread writer_thread(writer_func);

	reader_thread.join();
	writer_thread.join();
}

#endif // !VIDEO_41_IMPORTANT_RELATIONSHIPS
