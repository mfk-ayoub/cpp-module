#include "PmergeMe.hpp"

int main(int ac, char **av)
{   
    if (ac < 2)
    {
        std::cerr << "invalid argument" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe misort(av,ac);
        misort.CheckInput(av);
        misort.StartSorting();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }    
    return (0);
}