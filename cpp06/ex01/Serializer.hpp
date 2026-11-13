/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:43:17 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/08/08 23:35:55 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include "Data.hpp"
class Serializer
{
    private:
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& other);
    
    public:
        Serializer();
        ~Serializer();
        static  uintptr_t serialize(Data* ptr);

        static Data* deserialize(uintptr_t raw);
        
};