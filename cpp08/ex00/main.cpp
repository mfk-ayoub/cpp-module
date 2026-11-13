/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 06:50:52 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/07/30 08:38:19 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>

int main(void)
{
    std::vector <int> vec;
    vec.push_back(10);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(15);
    vec.push_back(8);
    vec.push_back(0);
    vec.push_back(5);

    try
    {
       std::cout << "The Number " << *::easyfind(vec,10) << " has been found" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::list <int> arr;
    
    for (int i = 1; i <= 10 ; ++i)
    {
        arr.push_back(i);
    }
    
    try
    {
        std::cout << "The Number " << *::easyfind(arr,5) << " has been found" << std::endl;
    }
    catch(const std::exception& e)
    {
         std::cerr << e.what() << std::endl;
    }

    //~~~~~~~~~~~~~~~~~~~~
    std::vector <int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);

    try
    {
        std::cout << "The Number " << *::easyfind(vect,5) << " has been found" << std::endl;
    }
    catch(const std::exception& e)
    {
         std::cerr << e.what() << std::endl;
    }
    return (0);   
}