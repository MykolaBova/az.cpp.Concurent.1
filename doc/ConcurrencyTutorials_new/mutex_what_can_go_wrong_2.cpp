#include <iostream>
#include <mutex>

class data_object{

public:
	void some_operation()
	{
		std::cout << "this is some operation \n";
	}
};


class data_wrapper{

	data_object protected_data;
	std::mutex m;

public:
	template <typename function>
	void do_some_work(function f)
	{
		std::lock_guard<std::mutex> lg(m);
		f(protected_data);
	}
};

data_object* unprotected_data;

void malisious_function(data_object& data)
{
	unprotected_data = &data;
}


int main()
{
	data_wrapper wrapper;
	wrapper.do_some_work(malisious_function);
	system("pause");
	return 0;
}

