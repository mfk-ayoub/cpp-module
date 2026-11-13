/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ScalarConverter.cpp                                :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/05/21 05:57:53 by ayel-mou          #+#    #+#             */
/* Updated: 2025/07/27 05:08:04 by ayel-mou         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{
  
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        *this =  other;
    }
    return (*this);
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudo(literal))
        printPseudo(literal);
    else if (isChar(literal))
        printChar(literal);
    else if (isInt(literal))
        printInt(literal);
    else if (isFloat(literal))
        printFloat(literal);
    else if (isDouble(literal))
        printDouble(literal);
    else
        printImpossible();
    
}


void ScalarConverter::printPseudo(const std::string& literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

void ScalarConverter::printChar(const std::string& literal)
{
    char c = literal[0];
    printCharConversion(c);
    printIntConversion(static_cast<int>(c));
    printFloatConversion(static_cast<float>(c));
    printDoubleConversion(static_cast<double>(c));
}

void ScalarConverter::printInt(const std::string& literal)
{
    long val = std::strtol(literal.c_str(), NULL, 10);
    printCharConversion(static_cast<char>(val));
    printIntConversion(static_cast<int>(val));
    printFloatConversion(static_cast<float>(val));
    printDoubleConversion(static_cast<double>(val));
}

void ScalarConverter::printFloat(const std::string& literal)
{
    std::string without_f = literal.substr(0, literal.length() - 1);
    float val = std::strtof(without_f.c_str(), NULL);
    printCharConversion(static_cast<char>(val));
    printIntConversion(static_cast<int>(val));
    printFloatConversion(val);
    printDoubleConversion(static_cast<double>(val));
}

void ScalarConverter::printDouble(const std::string& literal)
{
    double val = std::strtod(literal.c_str(), NULL);
    printCharConversion(static_cast<char>(val));
    printIntConversion(static_cast<int>(val));
    printFloatConversion(static_cast<float>(val));
    printDoubleConversion(val);
}

void ScalarConverter::printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printCharConversion(char c)
{
    std::cout << "char: ";
    if (std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "'" << c << "'" << std::endl;
    }
    else
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void ScalarConverter::printIntConversion(long val)
{
    std::cout << "int: ";
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(val) << std::endl;
    }
}

void ScalarConverter::printFloatConversion(float f)
{
    std::cout << "float: ";
    if (std::isinf(f) || std::isnan(f))
    {
        if (std::isinf(f))
        {
            if (f > 0)
                std::cout << "+inff" << std::endl;
            else
                std::cout << "-inff" << std::endl;
        }
        else
        {
            std::cout << "nanf" << std::endl;
        }
    }
    else if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        if (f == static_cast<long>(f))
        {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        }
        else
        {
            std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f << "f" << std::endl;
        }
    }
}

void ScalarConverter::printDoubleConversion(double d)
{
    std::cout << "double: ";
    if (std::isinf(d) || std::isnan(d))
    {
        if (std::isinf(d))
        {
            if (d > 0)
                std::cout << "+inf" << std::endl;
            else
                std::cout << "-inf" << std::endl;
        }
        else
        {
            std::cout << "nan" << std::endl;
        }
    }
    else if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        if (d == static_cast<long>(d))
        {
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        }
        else
        {
            std::cout << std::setprecision(std::numeric_limits<double>::digits10) << d << std::endl;
        }
    }
}

bool ScalarConverter::isInt(const std::string &literal)
{
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;

    if (start >= literal.length())
        return false;

    for (size_t i = start; i < literal.length(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(literal[i])))
            return false;
    }


    char* endptr;
    long val = strtol(literal.c_str(), &endptr, 10);
    return *endptr == '\0' && val >= INT_MIN && val <= INT_MAX;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;

    std::string without_f = literal.substr(0, literal.length() - 1);
    if (without_f.empty())
        return false;

    size_t start = 0;
    if (without_f[0] == '+' || without_f[0] == '-')
        start = 1;

    bool has_dot = false;
    bool has_digit = false;
    for (size_t i = start; i < without_f.length(); i++)
    {
        if (without_f[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(without_f[i])))
            has_digit = true;
        else
            return false;
    }
    return has_digit && has_dot;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;

    bool has_dot = false;
    bool has_digit = false;
    for (size_t i = start; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(literal[i])))
            has_digit = true;
        else
            return false;
    }
    return has_digit && has_dot;
}

bool ScalarConverter::isPseudo(const std::string& literal)
{
    return literal == "-inf" || literal == "+inf" || literal == "nan" ||
           literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 1 &&
           std::isprint(static_cast<unsigned char>(literal[0])) &&
           !std::isdigit(static_cast<unsigned char>(literal[0]));
}