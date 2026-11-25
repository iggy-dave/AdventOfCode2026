#pragma once

#include <string>
#include <vector>

class Utils
{
public:
    static std::vector<std::string> ReadLines(const std::string& FilePath);
    static std::string Trim(const std::string& Value);
    static std::vector<std::string> Split(const std::string& Value, char Delimiter);
    static bool IsInteger(const std::string& Value);
};
