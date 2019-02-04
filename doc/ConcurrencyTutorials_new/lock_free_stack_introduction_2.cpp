#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

template<typename T>
class lock_free_stack{

	struct node
	{
		std::shared_ptr<T> data;
		node * next;

		node(T& const _data) : data(std::make_shared<T>(_data))
		{}
	};

	std::atomic<node *> head;

public:

	void push(T& const _data)
	{
		node * new_node = new node(_data);												//1 create a new node
		new_node->next = head.load();											        //2 set new_node next to current head
		while (!head.compare_exchange_weak(new_node->next, new_node));                  //3 set head to next_node
	}


	std::shared_ptr<T> pop()
	{
		node * old_head = head;															//1 read the current value of head
		while (!head.compare_exchange_weak(old_head, old_head->next));					//2 set head to head->next   
		return	old_head ? old_head->data : std::shared_ptr<>();                        //5 returning the retrieved value
	}
};


int main()
{
	system("pause");
	return 0;
}