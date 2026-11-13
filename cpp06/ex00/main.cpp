#include "ScalarConverter.hpp"
#include <exception>

int main(int ac,char **av)
{
    (void)av;
    try
    {
        if (ac == 2)
        {
            ScalarConverter::convert(av[1]);
        }
        else 
        {
            throw std::string("Arugments Not Valid!");
        }
    }
    catch(const std::string& error)
    {
        std::cerr << "Error : " << error << std::endl;
    }
    
}