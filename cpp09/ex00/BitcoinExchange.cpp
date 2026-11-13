
#include "BitcoinExchange.hpp"
#include "utils.hpp"

BitcoinExchange::BitcoinExchange(std::string file) : _inputfile(file)
{
}

void BitcoinExchange::ReadInputfile()
{
    if (CheckIfFolder(_inputfile))
        throw IsNotFile();
    std::ifstream check(_inputfile.c_str(), std::ios::ate);
    if (check.tellg() == 0)
        throw EmptyFile();
    std::ifstream inputfile(_inputfile.c_str());
    GetData();
    if (!inputfile.is_open())
        throw FileNotFoundException();
    
    std::string line;
    std::string datakey, datavalue;
    if (std::getline(inputfile,line))
    {
        std::stringstream ss(line);
        if (std::getline(ss,datakey,'|') && std::getline(ss,datavalue))
        {
            trim(datakey);
            trim(datavalue);
            if (datakey !="date" || datavalue !="value")
            {
                std::cerr << "Error : Data and key Not valid" << std::endl;
                inputfile.close();
                return ;
            }
        }
    }
    while (std::getline(inputfile, line))
    {
        try
        {
            ProcessInputLine(line);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    inputfile.close();
    
}

void BitcoinExchange::ProcessInputLine(const std::string& line)
{
    std::string datakey, datavalue;
    float value;
    
    std::stringstream ss(line);
    if (std::getline(ss, datakey, '|') && !std::getline(ss, datavalue))
        throw BadInputException(datakey);

    trim(datakey);
    trim(datavalue);
    
    if (!CheckDate(datakey)) 
        throw BadInputException(datakey);
        
    std::stringstream svalue(datavalue);
    if (!(svalue >> value) || !svalue.eof()) 
        throw BadInputException(datakey);
    if (value < 0) 
        throw NegativeNumberException();
    if (value > 1000)
        throw TooLargeNumberException();
    DisplayResult(datakey, value);
}

void BitcoinExchange::DisplayResult(const std::string& date, float amount)
{

    float rate, result;
    rate = GetExchangeRate(date);
    result = amount * rate;
    std::cout << date << " => " << amount << " = " << result << std::endl;

}

float BitcoinExchange::GetExchangeRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = data.upper_bound(date);
    
    if (it == data.begin())
        throw std::runtime_error("No exchange rate available for this date.");
    
    --it;
    return it->second;
}


void  BitcoinExchange::GetData()
{
    std::ifstream datafile("data.csv");
    if (!datafile.is_open())
    {
        throw FileNotFoundException();
    }
    std::string line;
    std::string datakey , datavalue;
    float value;
    if (std::getline(datafile,line))
        ; 
    while (std::getline(datafile,line))
    {
        std::stringstream ss(line);
        if (std::getline(ss,datakey,',') && std::getline(ss,datavalue))
        {
            std::stringstream svalue(datavalue);
            svalue >> value;
            data.insert(std::pair<std::string, float>(datakey,value));

        }
    }
    datafile.close();
}

