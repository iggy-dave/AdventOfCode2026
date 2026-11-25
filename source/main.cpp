#include "Challenge.h"
#include "utils.h"

#include "day1/C1.h"
#include "day1/C2.h"
#include "day2/C1.h"
#include "day2/C2.h"
#include "day3/C1.h"
#include "day3/C2.h"
#include "day4/C1.h"
#include "day4/C2.h"
#include "day5/C1.h"
#include "day5/C2.h"
#include "day6/C1.h"
#include "day6/C2.h"
#include "day7/C1.h"
#include "day7/C2.h"
#include "day8/C1.h"
#include "day8/C2.h"
#include "day9/C1.h"
#include "day9/C2.h"
#include "day10/C1.h"
#include "day10/C2.h"
#include "day11/C1.h"
#include "day11/C2.h"
#include "day12/C1.h"
#include "day12/C2.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

std::string RunChallenge(int Day, int ChallengeNumber, const std::vector<std::string>& Input)
{
#define CREATE_DAY_CASE(DayNumber, DayType) \
        case DayNumber: \
        { \
            if (ChallengeNumber == 1) \
            { \
                DayType##C1 challenge; \
                return challenge.Solve(Input); \
            } \
            DayType##C2 challenge; \
            return challenge.Solve(Input); \
        }

    switch (Day)
    {
        CREATE_DAY_CASE(1, Day1)
        CREATE_DAY_CASE(2, Day2)
        CREATE_DAY_CASE(3, Day3)
        CREATE_DAY_CASE(4, Day4)
        CREATE_DAY_CASE(5, Day5)
        CREATE_DAY_CASE(6, Day6)
        CREATE_DAY_CASE(7, Day7)
        CREATE_DAY_CASE(8, Day8)
        CREATE_DAY_CASE(9, Day9)
        CREATE_DAY_CASE(10, Day10)
        CREATE_DAY_CASE(11, Day11)
        CREATE_DAY_CASE(12, Day12)
    default:
        return {};
    }

#undef CREATE_DAY_CASE
}

int main()
{
    try
    {
        std::string dayInput;
        std::string challengeInput;
        std::string inputPath;

        std::cout << "Day (1-12): ";
        std::getline(std::cin, dayInput);
        std::cout << "Challenge (1-2): ";
        std::getline(std::cin, challengeInput);

        const int day = std::stoi(dayInput);
        const int challengeNumber = std::stoi(challengeInput);
        if (day < 1 || day > 12 || challengeNumber < 1 || challengeNumber > 2)
        {
            std::cerr << "Day must be 1-12 and challenge must be 1-2.\n";
            return EXIT_FAILURE;
        }

        const std::string defaultInputPath = "source/day" + std::to_string(day) + "/input.txt";
        std::cout << "Data file [" << defaultInputPath << "]: ";
        std::getline(std::cin, inputPath);
        if (inputPath.empty())
        {
            inputPath = defaultInputPath;
        }

        const auto input = Utils::ReadLines(inputPath);
        std::cout << RunChallenge(day, challengeNumber, input) << '\n';
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
