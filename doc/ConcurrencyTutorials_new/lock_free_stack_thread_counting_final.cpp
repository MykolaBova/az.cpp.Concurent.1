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

	void reclaim_memory(node * old_head)
	{
		if (thread_count == 1)
		{
			node * claimed_list = to_be_deleted_list.exchange(nullptr);

			if (thread_count == 1)
			{
				//delete the claimed nodes
				while (claimed_list)
				{
					node* next = claimed_list->next;
					delete nodes;
					nodes = next;
				}
			}
			else if (nodes_to_delete)
			{
				//add nodes_to_delete list to to_be_deleted list
				node * last = claimed_list;
				while (node * const next = last->next)
				{
					last = next
				}

				last->next = to_be_deleted;
				while (!to_be_deleted.compare_exchange_weak(last->next, nodes_to_delete));
			}

			delete old_head;
		}
		else
		{
			//add old_head to to_be_deleted_list
			old_head->next = to_be_deleted_list;
			while (!to_be_deleted_list.compare_exchange_weak(old_head->next, old_head));
		}
	}

	std::atomic<node *> head;
	std::atomic<int> thread_count;
	std::atomic<node*>  to_be_deleted_list;

public:

	void push(T& const _data)
	{
		node * new_node = new node(_data);									     	   //1 create a new node
		new_node->next = head.load();											       //2 set new_node next to current head
		while (!head.compare_exchange_weak(new_node->next, new_node));                 //3 set head to next_node
	}


	std::shared_ptr<T> pop()
	{
		thread_count++;
		node * old_head = head;														//1 read the current value of head
		while (!head.compare_exchange_weak(old_head, old_head->next));              //2 set head to head->next   

		std::shared_ptr<T> result;
		if (old_head)
		{
			result = old_head->data;
		}

		reclaim_memory(old_head);

		return	result;															     //3 returning the retrieved value
	}
};


int main()
{
	system("pause");
	return 0;
}