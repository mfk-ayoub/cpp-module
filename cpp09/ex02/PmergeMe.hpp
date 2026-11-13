#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <iterator>

class PmergeMe
{
    private:
        char** _input;
        int ac;
        std::list<int> ListToSort;
        std::vector<int> VectorToSort;
        int singleNum;
        bool hassingleNum;
        double diffTimeVector;
        double diffTimeList;

        void DisplayVector(const std::vector<int>& vec);
        void DisplayList(const std::list<int>& lst);
        void DisplayChange(const std::string& message);
        std::vector<int> GenerateJacob(int n);
        void algoVector(std::vector<int>& main);
        int binarySearchVector(std::vector<int>& array, int target, int end);
        void algoList(std::list<int>& main);
        
    public: 
        PmergeMe(char **av, int ac);
        ~PmergeMe();
        
        void CheckInput(char **av);
        void StartSorting();

        template <typename Container>
        bool IsSorted(const Container& holder)
        {
            if (holder.empty())
                return true;
            typename Container::const_iterator it = holder.begin();
            typename Container::const_iterator next = it;
            ++next;
            while (next != holder.end())
            {
                if (*it > *next)
                    return false;
                it = next;
                ++next;
            }
            return true;
        }
};