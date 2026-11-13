/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 04:13:57 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/10/08 04:13:58 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "iter.hpp"
#include <string>
#include <iostream> 
#include <cctype>   

void printInt(int const &val)
{
    std::cout << val << std::endl;
}

void printString(std::string const &index)
{
    std::cout << index << std::endl;
}


void touppercase(std::string &s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
    }
}

int main(void)
{
    std::string FArray[] = {"Hello","ayoub","mfk"};
    size_t lenF = 3;

    ::iter(FArray,lenF,printString);
    

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    int  SArray[] = {10,20,30};
    size_t lenS = 3;

    ::iter(SArray,lenS,printInt);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    
    std::cout << "befor iter to touppercase " << std::endl;
    ::iter(FArray,lenF,printString);
    
    ::iter(FArray,lenF,touppercase); 

    std::cout << "after iter to touppercase " << std::endl;
    ::iter(FArray,lenF,printString);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    
}