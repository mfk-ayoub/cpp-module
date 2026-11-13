#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int count)
    : _input(av), ac(count), hassingleNum(false), diffTimeVector(0), diffTimeList(0)
{
}

PmergeMe::~PmergeMe() {}

void PmergeMe::CheckInput(char **av)
{
    std::string input;
    long num;
    char* endptr;
    
    std::vector<int> checker; 

    for (int i = 1; av[i]; i++)
    {
        input = av[i];
        if (input.empty())
            throw std::runtime_error("Error: empty input");
        num = std::strtol(input.c_str(), &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Error: invalid input");    
        if (num < 0 || num > INT_MAX)
            throw std::runtime_error("Error: input not a positive number or overflow");
        checker.push_back(num);
    }
    std::vector<int> temp = checker;
    std::sort(temp.begin(), temp.end());
    if (std::unique(temp.begin(), temp.end()) != temp.end())
         throw std::runtime_error("Error : find a duplicate");
}

std::vector<int> PmergeMe::GenerateJacob(int size)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    int i = 2;
    while (true)
    {
        int next = jacob[i - 1] + 2 * jacob[i - 2];
        if (next >= size)
        {
            jacob.push_back(next);
            break;
        }
        jacob.push_back(next);
        i++;
    }
    return jacob;
}

int PmergeMe::binarySearchVector(std::vector<int>& array, int target, int end)
{
    int start_array = 0;
    int end_array = end - 1;
    int index = 0;
    
    while (start_array <= end_array)
    {
        int mid = start_array + (end_array - start_array) / 2;
        if (array[mid] < target)
        {
            index = mid + 1;
            start_array = mid + 1;
        }
        else
            end_array = mid - 1;
    }
    return index;
}

void PmergeMe::algoVector(std::vector<int>& mainChain)
{
    size_t n = mainChain.size();
    if (n <= 1)
        return;

    bool hasStraggler = false;
    int straggler = 0;
    if (n % 2 != 0)
    {
        hasStraggler = true;
        straggler = mainChain.back();
        mainChain.pop_back();
    }

    std::vector<int> right;
    std::vector<int> left;
    
    for (size_t i = 0; i < mainChain.size(); i += 2)
    {
        if (mainChain[i] > mainChain[i+1])
        {
            right.push_back(mainChain[i]);
            left.push_back(mainChain[i+1]);
        }
        else
        {
            right.push_back(mainChain[i+1]);
            left.push_back(mainChain[i]);
        }
    }

    algoVector(right);
    
    std::vector<int> res = right;
    
    std::vector<int> jacobSeq = GenerateJacob(left.size());
    
    std::vector<bool> inserted(left.size(), false);
    
    for (size_t i = 0; i < jacobSeq.size() && i < left.size(); i++)
    {
        size_t idx = jacobSeq[i];
        if (idx >= left.size()) idx = left.size() - 1;
        
        for (int j = idx; j >= 0; j--)
        {
            if (!inserted[j])
            {
                int pos = binarySearchVector(res, left[j], res.size());
                res.insert(res.begin() + pos, left[j]);
                inserted[j] = true;
            }
        }
    }

    if (hasStraggler)
    {
        int pos = binarySearchVector(res, straggler, res.size());
        res.insert(res.begin() + pos, straggler);
    }

    mainChain = res;
}

void PmergeMe::algoList(std::list<int>& mainChain)
{
    size_t n = mainChain.size();
    if (n <= 1)
        return;

    bool hasStraggler = false;
    int straggler = 0;
    if (n % 2 != 0)
    {
        hasStraggler = true;
        straggler = mainChain.back();
        mainChain.pop_back();
    }

    std::list<int> right;
    std::list<int> left;
    
    std::list<int>::iterator it = mainChain.begin();
    while (it != mainChain.end())
    {
        int a = *it; it++;
        int b = *it; it++;
        if (a > b)
        {
            right.push_back(a); 
            left.push_back(b);
        }
        else
        {
            right.push_back(b); 
            left.push_back(a);
        }
    }

    algoList(right);

    std::list<int> res = right;
    
    std::vector<int> leftVec(left.begin(), left.end());
    std::vector<int> jacobSeq = GenerateJacob(leftVec.size());
    
    std::vector<bool> inserted(leftVec.size(), false);
    
    for (size_t i = 0; i < jacobSeq.size() && i < leftVec.size(); i++) 
    {
        size_t idx = jacobSeq[i];
        if (idx >= leftVec.size()) idx = leftVec.size() - 1;
        
        for (int j = idx; j >= 0; j--)
        {
            if (!inserted[j])
            {
                std::list<int>::iterator pos = std::lower_bound(res.begin(), res.end(), leftVec[j]);
                res.insert(pos, leftVec[j]);
                inserted[j] = true;
            }
        }
    }

    if (hasStraggler)
    {
        std::list<int>::iterator pos = std::lower_bound(res.begin(), res.end(), straggler);
        res.insert(pos, straggler);
    }
    
    mainChain = res;
}

void PmergeMe::StartSorting()
{
    if ((ac - 1) % 2 != 0)
    {
        singleNum = std::atoi(_input[ac - 1]);
        hassingleNum = true;
        ac--; 
    }

    for (int i = 1; i < ac; i++)
    {
        int num = std::atoi(_input[i]);
        ListToSort.push_back(num);
        VectorToSort.push_back(num);
    }

    if (IsSorted(VectorToSort) && !hassingleNum)
        return ;

    DisplayChange("before");

    std::clock_t start = std::clock();
    algoVector(VectorToSort);
    if (hassingleNum)
    {
        int pos = binarySearchVector(VectorToSort, singleNum, VectorToSort.size());
        VectorToSort.insert(VectorToSort.begin() + pos, singleNum);
    }
    std::clock_t end = std::clock();
    diffTimeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = std::clock();
    algoList(ListToSort);
    if (hassingleNum)
    {
        std::list<int>::iterator pos = std::lower_bound(ListToSort.begin(), ListToSort.end(), singleNum);
        ListToSort.insert(pos, singleNum);
    }
    end = std::clock();
    diffTimeList = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    DisplayChange("after");
    DisplayVector(VectorToSort);
    DisplayList(ListToSort);
}

void PmergeMe::DisplayVector(const std::vector<int>& SortedVector)
{
    std::cout << "Time to process a range of " << SortedVector.size() 
              << " elements with std::vector : " << diffTimeVector << " us" << std::endl;
}

void PmergeMe::DisplayList(const std::list<int>& SortedList)
{
    std::cout << "Time to process a range of " << SortedList.size() 
              << " elements with std::list : " << diffTimeList << " us" << std::endl;
}

void PmergeMe::DisplayChange(const std::string& message)
{
    std::cout << message << ": ";

    for (size_t i = 0; i < VectorToSort.size(); ++i) {
        std::cout << VectorToSort[i] << " ";
    }
    if (message == "before" && hassingleNum)
        std::cout << singleNum;
        
    std::cout << std::endl;
}