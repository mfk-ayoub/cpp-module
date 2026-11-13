/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:43:05 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/07/31 05:20:18 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
    :N(n)
{
    
}

Span::Span(const Span &copy)
{
    this->N = copy.N;
    this->vec = copy.vec;
}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
    {
        this->N = other.N;
        this->vec = other.vec;
    }
    return (*this);    
}

void Span::addNumber(int value) 
{
    if (vec.size() >= N) 
        throw SpanIsFull();
    vec.push_back(value);
}

int Span::shortestSpan(void)
{
    
    int shortspan;

    shortspan = __INT_MAX__;

    if (vec.size() <= 1)
    {
        throw SpanEllementNotEnough();
    }
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it; 
    
    for (it = tmp.begin(); it != tmp.end() - 1; ++it)
    {
        int diff; 
        diff = static_cast<int>(*(it + 1)) - *it;
        if (diff < shortspan)
            shortspan = diff;
  
    }
    return static_cast<int>(shortspan);
}

int Span::longestSpan(void)
{
    
    if (vec.size() <= 1)
    {
        throw SpanEllementNotEnough();
    }
    
    std::vector <int> tmp = vec;
    std::sort(tmp.begin(),tmp.end());
    return (tmp.back() - tmp.front());
}

Span::~Span()
{
    
}

const char * Span::SpanIsFull::what() const throw()
{
    return ("The Span is Full");
}

const char * Span::SpanEllementNotEnough::what() const throw()
{
    return ("The element is not enough");
}