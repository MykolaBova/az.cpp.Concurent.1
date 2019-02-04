#ifndef VIDEO_10_CODE
#define VIDEO_10_CODE

#include <iostream>
#include <thread>
#include <stdexcept>

#include "thread_guard.h"
#include "parallel_accumulate.h"


void run_code()
{
	int result = 0;
	std::vector<int> vec(10000);
	for (int i = 0; i < 10000; i++)
		vec[i] = 2;

	parallel_accumulate(vec.begin(), vec.end(), result);

	std::cout << "final result = " << result << std::endl;
}
#endif