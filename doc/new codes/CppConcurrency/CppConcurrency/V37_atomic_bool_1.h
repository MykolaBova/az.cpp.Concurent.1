#ifndef VIDEO_37_ATOMIC_BOOL_1
#define VIDEO_37_ATOMIC_BOOL_1

#include <iostream>
#include <thread>
#include <atomic>

void run_code()
{
	std::atomic<bool> flag_1;
	std::cout << "flag 1 = " << flag_1 << std::endl;
	  
	////cannot copy construct
	//std::atomic<bool> flag_2 (flag_1);

	////cannot copy assignable
	//std::atomic<bool> flag_3 = flag_1;

	//construct using non atomic boolean value
	bool non_atomic_bool = true;
	std::atomic<bool> flag_4(non_atomic_bool);
	std::cout << "flag 4 = " << flag_4 << std::endl;

	//assing non atomic boolean value
	std::atomic<bool> flag_5 = non_atomic_bool;
	std::cout << "flag 5 = " << flag_5 << std::endl;

}
#endif // !VIDEO_37_ATOMIC_BOOL_1
