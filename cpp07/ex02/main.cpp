/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 04:13:39 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/10/08 04:13:40 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>

void print(const Array<T>& arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(void)
{
   
    Array<int> arr(5);
    for (int i = 0; i < 5; i++)
        arr[i] = i;

    std::cout << "Size of arr: " << arr.size() << std::endl;

    Array<int> c(arr);

    print(arr);

    print(c);

    Array<std::string> words(3);
    words[0] = "ayoub";
    words[1] = "mfk";
    words[2] = "itami";

    print(words);
    
    Array<int> cop(5);
    cop[0] = 12;
    cop[1] = 6;
    cop[2] = 7;
    cop[3] = 8;
    cop[4] = 9;

    print(cop);

    cop = arr;
    print(cop);
    return 0;
}
