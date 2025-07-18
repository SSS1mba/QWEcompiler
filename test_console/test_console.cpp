#include <iostream>

int main()
{
    std::string s{ "fffggff" };
    std::cout << s.find_first_not_of("ff");
}

