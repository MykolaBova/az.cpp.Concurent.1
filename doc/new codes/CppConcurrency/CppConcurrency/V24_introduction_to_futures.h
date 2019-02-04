#ifndef VIDEO_24_CODE
#define VIDEO_24_CODE

#include <iostream>
#include <future>

int find_answer_how_old_universe_is()
{
	//this is not the ture value
	return 5000;
}

void do_other_calculations()
{
	std::cout << "Doing other stuff " << std::endl;
}

void run_code()
{
	std::future<int> the_answer_future = std::async(find_answer_how_old_universe_is);
	do_other_calculations();
	std::cout << "The answer is " << the_answer_future.get() << std::endl;
}

#endif // !VIDEO_24_CODE

