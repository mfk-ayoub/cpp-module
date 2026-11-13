#pragma once 

#include <stdexcept>

class FileNotFoundException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Error: could not open file.";
        }
};

class BadInputException : public std::exception
{
    private:
        std::string message_;

    public:
        BadInputException()
        {   
            message_ ="Error: Bad input.";
        }
        BadInputException(const std::string& msg)
        {
            message_ = "Error: Bad input => " + msg;
        }
        virtual ~BadInputException() throw() {}

        const char* what() const throw()
        {
            return message_.c_str();
        }
};

class NegativeNumberException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Error: not a positive number.";
        }
};

class TooLargeNumberException : public std::exception
{
    
    public:
        const char* what() const throw()
        {
            return "Error: too large a number.";
        }
};

class EmptyFile : public std::exception
{
    
    public:
        const char* what() const throw()
        {
            return "Error: fils is empty.";
        }
};

class IsNotFile : public std::exception
{
    
    public:
        const char* what() const throw()
        {
            return "Error: Is Not a File";
        }
};
