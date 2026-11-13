/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:35:34 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/21 08:11:47 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getlevel(std::string &level)
{
    const char* levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    return (0 * !strcmp(level.c_str(), levels[0])) + 
           (1 * !strcmp(level.c_str(), levels[1])) + 
           (2 * !strcmp(level.c_str(), levels[2])) +
           (3 * !strcmp(level.c_str(), levels[3])) +
           (4 * (strcmp(level.c_str(), levels[0]) && 
                 strcmp(level.c_str(), levels[1]) && 
                 strcmp(level.c_str(), levels[2]) && 
                 strcmp(level.c_str(), levels[3])));
}


void Harl::debug(void)
{
	std::cout <<  BLUE << "DEBUG " << RESET;
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;	
}
void Harl::info(void)
{
	std::cout << GREEN << "INFO " << RESET;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout <<  YELLOW << "WARNING " << RESET;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << RED << "ERROR " << RESET;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;	
}
Harl::Harl()
{
	
}
Harl::~Harl()
{
	
}
void  Harl::complain(std::string level)
{
	int index;
	void (Harl::*p)();  
	
	index = getlevel(level);

    switch (index)
    {
        case 0:
            p = &Harl::debug;
            (this->*p)();
        case 1:
            p = &Harl::info;
            (this->*p)();
        case 2:
            p = &Harl::warning;
            (this->*p)();
        case 3:
            p = &Harl::error;
            (this->*p)();
		break; 
		default:
		 	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
}