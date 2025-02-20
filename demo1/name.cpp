#include "utils.hpp"
#include "name.hpp"

void print_name()
{
    std::cout << "Enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << "You entered: " << name;
}