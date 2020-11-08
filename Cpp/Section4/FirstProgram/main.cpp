#include <iostream>
#include <string>

int main() 
{
    int favorite_number;
    std::cout << "Enter your favorite number between 1 and 100: ";
    std::cin >> favorite_number;
    std::string string_number= std::to_string(favorite_number);
    std::cout << "Amazing!! That's my favorite number too!\n"; 
    std::cout << "No really!!, "+string_number+" is my favorite number!"<< std::endl;
    return 0;
}