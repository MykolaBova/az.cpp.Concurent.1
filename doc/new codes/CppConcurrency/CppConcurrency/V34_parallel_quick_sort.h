#ifndef V34_PARALLEL_QUICK_SORT
#define V34_PARALLEL_QUICK_SORT

#include <iostream>
#include <list>
#include <algorithm>
#include <future>


template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
	std::cout << std::this_thread::get_id() << std::endl;
	if (input.size() < 2)
	{
		return input;
	}

	//move frist element in the list to result list and take it as pivot value
	std::list<T> result;
	result.splice(result.begin(), input, input.begin());
	T pivot = *result.begin();

	//partition the input array
	auto divide_point = std::partition(input.begin(), input.end(), [&](T const & t)
	{
		return t < pivot;
	});

	//move lower part of the list to separate list so that we can make recursive call
	std::list<T> lower_list;
	lower_list.splice(lower_list.end(), input, input.begin(), divide_point);

	auto new_lower(parallel_quick_sort(std::move(lower_list)));
	//auto new_upper(sequential_quick_sort(std::move(input)));
	std::future<std::list<T>> new_upper_future
	(std::async(&parallel_quick_sort<T>, std::move(input)));

	result.splice(result.begin(), new_lower);
	result.splice(result.end(), new_upper_future.get());
	return result;
}

void run_code()
{
	std::list<int> my_list;
	my_list.push_back(8);
	my_list.push_back(3);
	my_list.push_back(12);
	my_list.push_back(9);
	my_list.push_back(5);
	my_list.push_back(6);
	my_list.push_back(11);
	my_list.push_back(1);
	my_list.push_back(13);
	my_list.push_back(2);

	auto result = parallel_quick_sort<int>(my_list);

	for each (int var in result)
	{
		std::cout << var << std::endl;
	}
}

#endif // !V34_PARALLEL_QUICK_SORT
