

#include "utils.hpp" 

bool CheckIfFolder(const std::string &file)
{
    struct stat info;
    if (stat(file.c_str(), &info) != 0)
        return false; 

    return (info.st_mode & S_IFDIR) != 0; 
}

bool is_not_space(unsigned char ch)
{
    return !std::isspace(ch);
}

void trim(std::string &s)
{
   
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));

    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
}


bool CheckDate(const std::string &date)
{
    std::string yearStr , monthStr , dayStr;
    int year , month,day;
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    yearStr = date.substr(0, 4);
    monthStr = date.substr(5, 2);
    dayStr = date.substr(8, 2);

    year = std::atoi(yearStr.c_str());
    month = std::atoi(monthStr.c_str());
    day = std::atoi(dayStr.c_str());

    std::tm time_info;
    memset(&time_info, 0, sizeof(std::tm));
    time_info.tm_year = year - 1900; 
    time_info.tm_mon  = month - 1;   
    time_info.tm_mday = day;
    time_info.tm_isdst = -1;

    time_t timestamp = std::mktime(&time_info);
    if (timestamp < 0)
        return false;
    if (time_info.tm_year + 1900 != year ||
        time_info.tm_mon + 1 != month ||
        time_info.tm_mday != day)
    {
        return false;
    }

    return true;
}