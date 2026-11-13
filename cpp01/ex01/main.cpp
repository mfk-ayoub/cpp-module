/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:15:34 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/17 07:18:49 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac,char **av)
{
	(void)ac;
	(void)av;
	int i;
	int N;

	N = 5	;
	i = 0;
	Zombie *Z;
	
	Z = zombieHorde(N,"Dog");
	
	while (i < N)
	{
		Z[i].announce();
		i++;
	}
	if (Z)
		delete[] Z; 
	return (0);
}