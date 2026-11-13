/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:03:53 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/08/04 11:49:10 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data *data = new Data;

    data->id = 0606;
    data->name = "ayoub";
    
    uintptr_t i = Serializer::serialize(data);
    
    Data *idata = Serializer::deserialize(i);

    std::cout << "id = " << idata->id << std::endl;
    std::cout << "name = "  << idata->name << std::endl;   
    

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl; 
    Data sec;

    sec.id = 12;
    sec.name = "mfk";

    uintptr_t ise = Serializer::serialize(&sec);
    Data *sdata = Serializer::deserialize(ise);
    std::cout << "id = " << sdata->id << std::endl;
    std::cout << "name = "  << sdata->name << std::endl;   
    
    
    
    delete data;
    return (0);
}