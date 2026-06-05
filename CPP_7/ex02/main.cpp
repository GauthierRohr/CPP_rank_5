#include <iostream>
#include <string>
#include "Array.hpp"

int main(int, char**)
{
    try
    {
        std::cout << "Creating array with default constructor..." << std::endl;
        Array<char> empty;
        std::cout << "Array size: " << empty.size() << std::endl << std::endl;
    
        std::cout << "Creating array with uint constructor..." << std::endl;
        Array<int> total(10);
        std::cout << "Array contents: ";
        for (size_t i = 0; i < total.size(); i++)
            std::cout << (total[i] = i);
        std::cout << std::endl << std::endl;

        std::cout << "Testing assignment operator depth..." << std::endl;
        Array<int> copy = total;
        std::cout << "Copy: ";
        for (size_t i = 0; i < copy.size(); i++)
            std::cout << copy[i];
        std::cout << std::endl;
        
        std::cout << "Modified copy: ";
        for (size_t i = 0; i < copy.size(); i++)
            std::cout << ++copy[i];
        std::cout << std::endl;
        
        std::cout << "Original array: ";
        for (size_t i = 0; i < total.size(); i++)
            std::cout << total[i];
        std::cout << std::endl << std::endl;
		
		Array<std::string> words(3);
		words[0] = "J'aime";
		words[1] = "tres beaucoup";
		words[2] = "le tennis";

		for (size_t i = 0; i < words.size(); ++i)
			std::cout << words[i] << std::endl;
		std::cout << std::endl;
		std::cout << "Testing out of bounds: ";
        total[11] = -1;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    
    return 0;
}