#include <iostream>
#include <thread>
#include <atomic>

template<typename T>
class lock_free_stack{

	struct node
	{
		T data;
		node * next;


		node(T& const _data) : data(_data)
		{}
	};

	node * head;

public:

	void push(T& const _data)
	{
		node * new_node = new node(_data); //create a new node
		new_node->next = head;             //set new_node next to current head
		head = new_node;                   //set head to next_node
	}


	T pop()
	{
		node * old_head = head;   //1 read the current value of head
		head = old_head->next;    //2 set head to head->next   
		T value = old_head->data; //3 retrieve the data from the current head
		delete  old_head;         //4 delete previous head node
		return value;             //5 returning the retrieved value
	}
};


//int main()
//{
//	system("pause");
//	return 0;
//}