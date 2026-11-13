/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 04:23:29 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/07/26 04:58:39 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>

void iter(T *arr, size_t len, void (*func)(T const &))
{
    if (arr == NULL || func == NULL)
        return ;
    for (size_t i = 0 ; i < len ; i++)
    {
        func(arr[i]);
    }
}

template <typename T>
void iter(T *arr, size_t len, void (*func)(T &))
{
    if (arr == NULL || func == NULL)
        return ;
    for (size_t i = 0 ; i < len ; i++)
    {
        func(arr[i]);
    }
}
