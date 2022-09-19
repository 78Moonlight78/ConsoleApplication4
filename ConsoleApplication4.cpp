#include <bitset>
#include <iostream>

int main()
{
    float x = 15.375;
    unsigned long int y = 12566;

    std::cout << std::bitset<sizeof(y)* CHAR_BIT>(y);
    std::cout << '\n';
    //метод по преобразованию float в двоичное предстваление 
    for (int i = sizeof(x) - 1; i >= 0; i--)
        std::cout << std::bitset<8>(reinterpret_cast<char*>(&x)[i]);
    std::cout << '\n';
}