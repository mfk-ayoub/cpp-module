/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:04:45 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/21 10:18:41 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &wepeon);
		void attack();
};

