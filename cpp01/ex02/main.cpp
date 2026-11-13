/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 04:40:34 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/14 05:29:34 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


int main(void)
{
	std::string Brain;
	Brain =  "HI THIS IS BRAIN";
	std::string* stringPTR = &Brain;
	std::string &stringREF = Brain;
	
	std::cout <<"memory address " << &Brain <<  " of the string variable" <<  std::endl;
	std::cout <<"memory address " <<   stringPTR <<  " held by stringPTR" << std::endl;
	std::cout <<"memory address " <<   &stringREF <<  " held by stringREF" << std::endl;

	std::cout << "The value " << Brain << " of the string variable." <<  std::endl;
	std::cout << "The value " << *stringPTR << " pointed to by stringPTR." << std::endl;
	std::cout << "The value " << stringREF <<" pointed to by stringREF."<< std::endl;
}