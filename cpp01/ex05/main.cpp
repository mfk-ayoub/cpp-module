/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:26:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/23 05:07:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	std::cout << "test for debug" << std::endl;
	harl.complain("debug");

	std::cout << "test for info" << std::endl;
	harl.complain("info");

	std::cout << "test for warning" << std::endl;
	harl.complain("warning");

	std::cout << "test for error" << std::endl;
	harl.complain("error");
	return (0);
}