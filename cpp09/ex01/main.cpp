#include "RPN.hpp"

int main(int ac,char **av)
{
  
    if (ac != 2)
    {
        std::cerr  <<  "invalid argument" << std::endl;
        return (1);
    }
    RPN  rpn;
    rpn.Proccess(av[1]);
    
    return (0);
}