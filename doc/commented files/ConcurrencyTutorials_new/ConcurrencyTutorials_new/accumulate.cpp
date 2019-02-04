#include <thread>
#include <numeric>
#include <vector>
#include <algorithm>
#include<iostream>

template<typename iterator, typename T>
void accumulate_block(iterator start, iterator end, T& result)
{
	result = std::accumulate(start, end, result);
	std::cout << std::this_thread::get_id() << "--" << result << "\n";
}


template<typename iterator, typename T>
T accumulate_list(iterator start, iterator end, T init)
{
	//get size of the input list
	int distance = std::distance(start, end);
	if (!distance)
	{
		return init;
	}

	//we set minimum number of threads to run in each thread
	const int min_elements = 500;
	//max threads depend on min elements for each threads
	int max_threads = distance / min_elements;
	std::cout << "Max number of threads to run to avoid heavy overload -" << max_threads << std::endl;

	// max threads hardware allowed to run concurrently
	int allowed_thread = std::thread::hardware_concurrency();
	std::cout << "Max number of threads to run to avoid oversubscription -" << allowed_thread << std::endl;

	// get  the minimum of above two values, to avoid both oversubscription and heavy overload
	int runing_threads = std::min(allowed_thread > 0 ? allowed_thread : 2, max_threads);
	std::cout << "Runing threads -" << runing_threads << std::endl;

	// reduced result list, this is were we store result of each block
	std::vector<T>  results(runing_threads );

	// vector to store number of threads
	std::vector<std::thread> threads(runing_threads-1);

	iterator block_start = start;
	// decide block size based on number of runing thread
	int block_size = distance / (runing_threads);

	//send perticular block of data to separate thread to accumulate
	for (int i = 0; i < (runing_threads-1); i++)
	{
		iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(accumulate_block<iterator, T>, block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}
	
	//accumulate last block in this thread
	accumulate_block<iterator, T>(block_start, end, results[runing_threads-1]);
	
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(), results.end(), init);
}

//int main()
//{
//	int number_of_elements = 5000;
//	std::vector<int> values(number_of_elements);
//	for (int i = 0; i < number_of_elements; i++)
//		values[i] = i;
//	int val = 0;
//
//	long addition = accumulate_list(values.begin(), values.end(), val);
//	std::cout << "Summation of list  -" << addition << std::endl;
//	system("pause");
//	return 0;
//}