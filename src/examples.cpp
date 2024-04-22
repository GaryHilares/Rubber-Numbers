#include "../include/RubberNumbers/RubberNumbers.hpp"

int main()
{
    using namespace RubberNumbers;
    RubberInt test1(RubberInt(45));
    test1 = test1 * RubberInt(-69);
    std::cout << test1 << std::endl;
    RubberFloat test2(RubberFloat(45.4));
    test2 = test2 * RubberFloat(-69);
    std::cout << test2 << std::endl;
}
