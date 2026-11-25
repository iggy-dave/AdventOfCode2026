#include "utils.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <stdexcept>

std::vector<std::string> Utils::ReadLines(const std::string& FilePath)
{
    std::ifstream input(FilePath);
    if (!input)
    {
        throw std::runtime_error("Unable to open input file: " + FilePath);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line))
    {
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }
        lines.push_back(line);
    }
    return lines;
}

std::string Utils::Trim(const std::string& Value)
{
    const auto first = std::find_if_not(Value.begin(), Value.end(),
        [](unsigned char Character) { return std::isspace(Character) != 0; });
    const auto last = std::find_if_not(Value.rbegin(), Value.rend(),
        [](unsigned char Character) { return std::isspace(Character) != 0; }).base();

    if (first >= last)
    {
        return {};
    }
    return { first, last };
}

std::vector<std::string> Utils::Split(const std::string& Value, char Delimiter)
{
    std::vector<std::string> parts;
    std::string part;
    for (const char character : Value)
    {
        if (character == Delimiter)
        {
            parts.push_back(part);
            part.clear();
        }
        else
        {
            part += character;
        }
    }
    parts.push_back(part);
    return parts;
}

bool Utils::IsInteger(const std::string& Value)
{
    if (Value.empty())
    {
        return false;
    }

    const std::size_t start = Value.front() == '-' || Value.front() == '+' ? 1 : 0;
    return start < Value.size() && std::all_of(Value.begin() + static_cast<std::ptrdiff_t>(start), Value.end(),
        [](unsigned char Character) { return std::isdigit(Character) != 0; });
}
