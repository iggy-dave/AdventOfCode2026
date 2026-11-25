#pragma once

#include <string>
#include <vector>

class Challenge
{
public:
    virtual ~Challenge() = default;

    virtual std::string Solve(const std::vector<std::string>& Input) const = 0;
};
