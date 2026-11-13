/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 04:13:44 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/10/08 04:13:45 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
    private:
        T* arr;
        unsigned int _size;

    public:
        Array();

        Array(unsigned int n);

        Array(const Array& other);

        Array& operator=(const Array& other);

        T& operator [](unsigned int index);

        const T& operator [](unsigned int index) const;

        ~Array();

        unsigned int size() const;

        class IndexNotValid : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Index is out of bounds");
                }
        };
};


#include "Array.tpp"

