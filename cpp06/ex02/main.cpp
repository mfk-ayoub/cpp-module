/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:32:01 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/08/09 01:10:56 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(NULL));
    int n = rand() % 3 ;
    if (n == 0)
        return (new A);
    else  if (n == 1)
        return (new B);
    else 
        return (new C);
}

void identify(Base* p)
{
    
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)(a);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try 
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "unknown" << std::endl;
}

int main(void)
{
    Base *b =  generate();
    Base &ref  = *b;
    identify(b);
    identify(ref);
    delete b;
    return (0);
}
