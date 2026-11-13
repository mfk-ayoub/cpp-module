#include "RPN.hpp"

RPN::RPN() 
    : total(0)
{

}

bool RPN::IsOperator(int c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::IsOnlyWhitespace(const std::string& input)
{

    for (size_t i = 0; i < input.length(); ++i)
    {
      
        if (!isspace(static_cast<unsigned char>(input[i])))
            return false; 
    }
    return true;
}

bool RPN::CheckInput(const std::string &input)
{
    std::istringstream iss(input);
    std::string s;

    int i;

    i = 0;
    while (iss >> s)
    {
        if (s.length() == 1 && isdigit(s.at(0)))
            i++;
        else if (s.length() == 1 && IsOperator(s.at(0)))
        {
            if (i < 2)
                return false;
            i--;  
        }
        else 
            return false;
    }
    return i == 1;

}


void RPN::Proccess(const std::string &input)
{
    std::istringstream iss(input);
    std::string s;
    int a;
    int b;
    try
    {
        if (input.empty() || IsOnlyWhitespace(input))
            throw std::runtime_error("Error");     
        if (!CheckInput(input))
            throw std::runtime_error("Error");
        while (iss >> s)
        {
            if (isdigit(s.at(0)))
                this->_stack.push(std::atoi(s.c_str()));
            if(IsOperator(s.at(0)))
            {   
                a = _stack.top();
                _stack.pop();
                b = _stack.top();
                _stack.pop();

                if (s.at(0) == '+')
                    this->_stack.push(b + a); 
                else if (s.at(0) == '-')
                    this->_stack.push(b - a); 
                else if (s.at(0) == '/')
                {
                    if (a == 0) 
                        throw std::runtime_error("Error: Division by 0");
                    this->_stack.push(b / a);
                }
                else if (s.at(0) == '*')
                    this->_stack.push(b * a); 
            }
        } 
        this->total = this->_stack.top();
        this->_stack.pop();
        std::cout << this->total << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
}
