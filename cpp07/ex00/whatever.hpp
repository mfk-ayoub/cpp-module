/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 03:44:30 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/07/26 04:07:11 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template  < typename S>

void swap(S &first , S &second)
{
   
    S tmp = first;
    first = second;
    second = tmp;
}

template  < typename MI>
MI min(const MI &f , const MI &s)
{
    if (f <= s)
        return (f);
    else
        return (s);
}

template  < typename MA>

MA max(const MA &f , const MA &s)
{
    if (f <= s)
        return (s);
    else 
        return (f);
}
