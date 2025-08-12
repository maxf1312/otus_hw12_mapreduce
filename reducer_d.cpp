#include <iostream>
#include <string>
#include <limits>
#include <iomanip>


int main(int argc, char ** argv)
{
    constexpr auto max_precision{std::numeric_limits<double>::digits10 + 1}; 

    size_t count = 0;
    long double summ = 0.0;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty())
    {
        count += 1;
        summ += std::stod(line); 
    }

    summ /= static_cast<decltype(summ)>(count - 1);
    std::cout << std::fixed << std::setprecision(max_precision) << summ << std::endl;
    return 0;
}