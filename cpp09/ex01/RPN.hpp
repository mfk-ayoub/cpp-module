
#include <stdexcept>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstring>
#include <algorithm> 
#include <cctype> 

class RPN
{
    private:
        std::stack <int> _stack;
        int total;
        bool IsOperator(int c);
        bool CheckInput(const std::string &input);
        bool IsOnlyWhitespace(const std::string& input);
    public:
        RPN();
        void Proccess(const std::string &input);
};
