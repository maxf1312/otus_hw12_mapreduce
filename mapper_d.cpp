#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>

#include "csv_line.h"

constexpr const size_t CSV_Index_Price = 9;
constexpr const size_t CSV_Index_ID = 0;

int main(int argc, char ** argv)
{
    std::string line;
    CSV_Line csv_line;
    
    if( !std::getline(std::cin, line) )
    {
        std::cerr << "Error: empty input!" << std::endl;
        return -1;
    }

    csv_line.parse(line);
    if( csv_line.col_count() > 1 )
    {
        std::cerr << "Error: first line must have average price only!" << std::endl;
        return -2;
    }

    size_t stod_idx{};
    long double avg_price = std::stold(line, &stod_idx);
    if( fabsl(avg_price - 0.0) < std::numeric_limits<long double>::epsilon() && stod_idx < 1 )
    {
        std::cerr << "Error: first line must have double not zero number!" << std::endl;
        return -3;
    }

    constexpr int max_precision{std::numeric_limits<long double>::digits10 + 1}; 

    for (; std::getline(std::cin, line) && !line.empty(); csv_line.clear())
    {
        csv_line.parse(line);
        long double price = std::stold(csv_line[CSV_Index_Price]);
        long double square_of_diff = price - avg_price;
        square_of_diff *= square_of_diff;
        std::cout << std::fixed << std::setprecision(max_precision) << square_of_diff << std::endl;
    }

    return 0;
}