

#pragma once


#include <string>
#include <map>
#include <exception>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ErrorClasses.hpp"

class BitcoinExchange
{
	private:
		std::string _inputfile;
		std::map<std::string, float> data;
		void ProcessInputLine(const std::string& line);
		void DisplayResult(const std::string& date, float amount);
		float GetExchangeRate(const std::string& date);
		void GetData();

	public:
		BitcoinExchange(std::string file);
		void ReadInputfile();
};

