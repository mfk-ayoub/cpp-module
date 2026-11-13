/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 05:46:10 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/10/08 05:53:45 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class ErrorNotFound : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Not Found");
        }
};

template <typename T>

typename T::iterator easyfind(T &arr, int to_find)
{
    typename T::iterator it = std::find(arr.begin(), arr.end(), to_find);

    if (it == arr.end())
    {
        throw ErrorNotFound();
    }
    return (it);
}