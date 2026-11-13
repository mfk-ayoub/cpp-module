/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:42:41 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/01/28 06:42:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int  main(int ac,char **av)
{
	int 	counter;
	int 	i;
	char	c;

	i = 0;
	counter = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (counter < ac)
	{
		i = 0;
		while (av[counter][i])
		{
			c = toupper(av[counter][i]);
			std::cout << c;
			i++;
		}
		counter++;
	}
	std::cout << '\n';
	return (0);
}

