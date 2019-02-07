
#include <string>
#include <iostream>

int main()
{
    std::string a = "";
    std::string *a_ptr = &a;
    std::cout << "a_ptr->" << a_ptr << "<-" << std::endl;
    a_ptr = nullptr;
    std::cout << "a_ptr->" << a_ptr << "<-" << std::endl;

    return 0;
}