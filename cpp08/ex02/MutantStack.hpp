/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* MutantStack.hpp                                    :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/07/31 05:40:28 by ayel-mou          #+#    #+#             */
/* Updated: 2025/08/11 02:57:08 by ayel-mou         ###   ########.fr       */
/* */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack();
    MutantStack(const MutantStack& copy);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
   
};

#include "MutantStack.tpp"