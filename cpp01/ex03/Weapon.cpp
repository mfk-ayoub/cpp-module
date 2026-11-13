/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:00:21 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/14 05:26:24 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
	return (type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}

Weapon::Weapon(std::string type) : type(type)
{
	
}

Weapon::~Weapon()
{

}