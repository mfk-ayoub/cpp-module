/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:19:01 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/26 02:32:07 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int  i;
	
	i = 0;
    if (N <= 0)
        return NULL;

    Zombie* horde;
    try
    {
        horde = new Zombie[N];
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
    }
	
    while (i < N)
	{
        horde[i].setName(name);
		i++;
	}
    return (horde);
}
