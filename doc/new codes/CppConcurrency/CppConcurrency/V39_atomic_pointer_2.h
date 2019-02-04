#ifndef VIDEO_39_ATOMIC_POINTER_2
#define VIDEO_39_ATOMIC_POINTER_2
#include <iostream>
#include <thread>
#include <atomic>

void  run_code()
{
	//int values[20];

	//for (int i = 0; i < 20; i++)
	//	values[i] = i+1;

	//std::atomic<int*> x_pointer = values;

	std::atomic<int*> x_pointer;

	for (int i = 0; i < 20; i++)
		x_pointer[i] = i+1;

	std::cout << "1. After initialization value pointed by atomic pointer          - " 
		<< *x_pointer << std::endl;

	//fetch_add
	int * prev_pointer_val_1 = x_pointer.fetch_add(12);

	std::cout << "2. After fetch add previous value pointed by atomic pointer - " 
		<< *prev_pointer_val_1 << std::endl;
	std::cout << "2. After fetch add new value pointed by atomic pointer      - " 
		<< *x_pointer << std::endl;

	//fetch_sub
	int * prev_pointer_val_2 = x_pointer.fetch_sub(3);

	std::cout << "3. After fetch sub previous value pointer by atomic pointer - " 
		<< *prev_pointer_val_2 << std::endl;
	std::cout << "3. After fetch sub new value pointed by atomic pointer      - " 
		<< *x_pointer << std::endl;

	//++ operator
	x_pointer++;
	std::cout << "4. After post increment value pointed by atomic pointer          - " 
		<< *x_pointer << std::endl;

	//-- operator
	x_pointer--;
	std::cout << "5. After post decrement value pointed by atomic pointer          - "
		<< *x_pointer << std::endl;

}

#endif