#include "functionalities.h"
#include "functionalities.h"
#include <iostream>

/// Checks is a given string is a number.
/// \param string the given string
/// \return true if the string contains only digits, false otherwise
bool is_number(const std::string& string)
{
    std::string::const_iterator it = string.begin();
    while (it != string.end() && std::isdigit(*it)) ++it;
    return !string.empty() && it == string.end();
}