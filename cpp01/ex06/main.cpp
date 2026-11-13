/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:10:39 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/21 08:08:40 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac,char **av)
{
	
	if (ac != 2)
	{
		std::cout <<  "[!] Arguments Not Valid" << std::endl;
		return (1); 
	}
	Harl harl;

	harl.complain(av[1]);
	return (0);
}
