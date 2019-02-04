#include <iostream>
#include <thread>
#include <atomic>


int main()
{
	int values[20];

	for (int i = 0; i < 20; i++)
		values[i] = i+1;

	std::atomic<int*> x_pointer = values;
	std::cout << "1. After initialization value pointed by atomic pointer          - " << *x_pointer << std::endl;

	int * prev_pointer_val_1 = x_pointer.fetch_add(12);
	std::cout << "2. After fetch add previous value pointed by atomic pointer - " << *prev_pointer_val_1 << std::endl;
	std::cout << "2. After fetch add new value pointed by atomic pointer      - " << *x_pointer << std::endl;

	int * prev_pointer_val_2 = x_pointer.fetch_sub(3);
	std::cout << "3. After fetch sub previous value pointer by atomic pointer - " << *prev_pointer_val_2 << std::endl;
	std::cout << "3. After fetch sub new value pointed by atomic pointer      - " << *x_pointer << std::endl;

	x_pointer++;
	std::cout << "4. After post increment value pointed by atomic pointer          - " << *x_pointer << std::endl;

	x_pointer--;
	std::cout << "5. After post decrement value pointed by atomic pointer          - " << *x_pointer << std::endl;

	system("pause");
	return 0;
}