#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

#include "csv_line.h"


constexpr const size_t CSV_Index_Price = 9;
constexpr const size_t CSV_Index_ID = 0;

int main(int argc, char ** argv)
{
    constexpr int max_precision{std::numeric_limits<long double>::digits10 + 1}; 
    std::string line;
    CSV_Line csv_line;
    for (; std::getline(std::cin, line) && !line.empty(); csv_line.clear())
    {
        csv_line.parse(line);
        std::cout << std::fixed << std::setprecision(max_precision) << std::stold(csv_line[CSV_Index_Price]) << std::endl;
    }

    return 0;
}