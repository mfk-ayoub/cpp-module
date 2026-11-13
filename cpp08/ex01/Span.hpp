/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:40:54 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/07/31 05:20:26 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector <int> vec;
    public:
        Span(unsigned int n);

        Span(const Span &copy);

        Span& operator=(const Span& other);

        void addNumber(int value);

        int shortestSpan(void);
        
        int longestSpan(void);
        
        class SpanIsFull : public std::exception
        {
            public:
                virtual const char * what() const throw();

        };
        class SpanEllementNotEnough : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        ~Span();
};