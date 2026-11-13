/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 05:30:21 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/07/27 05:08:25 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>   
#include <climits>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    private:
        static bool isPseudo(const std::string& literal);
        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
        static void printCharConversion(char c);
        static void printIntConversion(long val);
        static void printFloatConversion(float f);
        static void printDoubleConversion(double d);
        static void printChar(const std::string& literal);
        static void printInt(const std::string& literal);
        static void printFloat(const std::string& literal);
        static void printDouble(const std::string& literal);
        static void printPseudo(const std::string& literal);
        static void printImpossible();

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
        static void convert(const std::string& literal);
};