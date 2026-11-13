/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 06:31:21 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/17 01:11:50 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacing.hpp"

int main(int ac, char **av)
{
	std::fstream file;
	if (ac != 4)
	{
		std::cout << "[!] Missing Arguments" << std::endl;
		return (1);
	}
	file.open(av[1],std::ios::in | std::ios::out);
	if (!file.is_open())
	{
		std::cout << "[!] Error opening file" << std::endl;
		return (1);
	}
	if (file.eof())
	{
		std::cout << "[!] Error file is empty" << std::endl;
		file.close();	
		return (1);
	}
	replacing(av[2], av[3], file,av[1]);
	file.close();
}