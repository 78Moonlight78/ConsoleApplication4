#include <bitset>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

bool correct_float(string s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}
/// <summary>
/// 7. Поменять местами значения рядом стоящих бит в парах. Количество пар и номер старшего разряда левой пары задаётся с клавиатуры.
/// </summary>
/// <param name="n"></param>
template<size_t N>
void function_7(bitset<N> n) {
    
}


int main()
{
    union
    {
        float input; // assumes sizeof(float) == sizeof(int)
        int   output;
    } data;
    string sf, su;

    
    data.input = 2.25125;
    unsigned long int y = 12566;
    
    do {
        cin >> sf;
    } while (correct_float(sf) != 1);
    cout << "Corrrect";
    cin >> su;
    y = stoul(su);

    data.input = stof(sf);
    //метод по преобразованию unsigned long  в двоичное предстваление
    bitset<sizeof(y)* CHAR_BIT> a1 (y) ;

    //метод по преобразованию float в двоичное предстваление 
    bitset<sizeof(float)* CHAR_BIT> bits(data.output);
    cout << bits<<"\n";

    function_16(bits);
    cout << a1;
}