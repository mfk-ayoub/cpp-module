/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacing.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:21:19 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/17 01:37:51 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacing.hpp"

void WritingInNew(std::string s1, std::string s2, std::string line, std::ofstream &filereplace)
{
    size_t pos;
    std::string result;
	
	pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        result += line.substr(0, pos);
        result += s2;
        pos += s1.length();
        line = line.substr(pos);
        pos = 0;
    }

    result += line;
    filereplace << result << std::endl;
}


void replacing(std::string s1,	std::string s2,std::fstream &file,std::string name)
{
	if (s1.empty() || s2.empty())
	{
		std::cout << "[!] Error string is empty" << std::endl;
		return ;
	}

	std::string new_name;
	std::string line;
	
	new_name =  name + ".replace";
	std::ofstream filereplace(new_name.c_str(), std::ios::out); 
	
	if (!filereplace.is_open())
	{
		std::cout << "[!] Error opening file replace" << std::endl;
		return ;
	}
	while (std::getline(file, line))
        WritingInNew(s1, s2, line, filereplace);
	filereplace.close();		
}



