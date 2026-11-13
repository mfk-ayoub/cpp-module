

#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2) 
            throw FileNotFoundException();
        
        BitcoinExchange btc(argv[1]);
        btc.ReadInputfile();
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    
    return (0);
}