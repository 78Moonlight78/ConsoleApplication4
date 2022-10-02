#include <bitset>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;


bool check_UI(string s) {
    for (int i = 0; i < strlen(s.c_str()); i++) {
            /// <summary>
            /// /if ((isdigit(s[i]) == 0 && i != 0)||(i == 0 && (s[i] != '+' || isdigit(s[i]) == 0))) {     return 0;}
  
            /// </summary>
            /// <param name="s"></param>
            /// <returns></returns>
        if ((isdigit(s[i]) == 0 && i != 0) || (i == 0 && (s[i] != '+' && isdigit(s[i]) == 0))) {
            cout << s[i];
            return 0;
        }
            
    }
    return 1;

}

bool correct_float(string s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}
/// <summary>
/// 7. Поменять местами значения рядом стоящих бит в парах. Количество пар и номер старшего разряда левой пары задаётся с клавиатуры.
///
/// </summary>
/// <param name="n"></param>
unsigned int swapBitsUI(unsigned int  n, int p1, int p2)
{
    //left-shift 1 p1 and p2 times
    //and using XOR
    if (((n & (1 << p1)) >> p1) ^ ((n & (1 << p2)) >> p2))
    {
        n ^= 1 << p1;
        n ^= 1 << p2;
    }
    return n;
}
unsigned int swapUI(unsigned int n, int id, int count) {
    for (int i = id; i> id - count*2  ; i -= 2) {
        n = swapBitsUI(n, i, ++i);
    }
    return n;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int id, count, n = 0;
    union
    {
        float input; // assumes sizeof(float) == sizeof(int)
        int   output;
    } data;
    string sf="a", su = "a";
    unsigned long int y;
    cout << "Введите значение типа float(вввещественное число): ";
    do {
        if (sf != "a") {
            cout << "Неверный ввод, попробуйте еще раз: ";
        }
        cin >> sf;
    } while (correct_float(sf) != 1);
    cout << "Верно!\n";

    cout << "Введите значение типа unsigned int(натуральное число): ";
    
    do {
        if (su != "a") {
            cout << "Неверный ввод, попробуйте еще раз: ";
        }
        cin >> su;
    } while (check_UI(su) != 1);
    cout << "Верно!"<< endl;
    y = stoul(su);
    data.input = stof(sf);
    while (n !=4) {
        cout << "0: Вывести битовые значения числа float\n";
        cout << "1: Вывести битовые значения числа unsigned int\n";
        cout << "2: Поменять местами пары битов в float\n";
        cout << "3: Поменять местами пары битов в unsugned int\n";
        cout << "4: Завершить программу\n"<<"Ваше решение:";
        cin >> n;
        if (!cin) {
            cout << "Ошибка! Введено не число, попробуйте еще раз."<<endl;
            cin.clear(); // Снятие ошибки
            cin.get();
            n = 5;
        }
        while (n<0 && n>4) {
            cout << "Неверно! попробуйте еще раз: ";
            cin >> n;
        }
        if (n == 0) {
            //метод по преобразованию float в двоичное предстваление 
            bitset<sizeof(float)* CHAR_BIT> bits(data.output);
            cout << "Значение float: " << bits<<"\n";
        }
        else if (n == 1) {
            //метод по преобразованию unsigned long  в двоичное предстваление
            bitset<sizeof(y)* CHAR_BIT> a1(y);
            cout << "Значение unsigned int: " << a1 << endl;
        }
        else if (n == 2) {
            cout << "Введитe номер элемента: ";
            cin >> id;
            cout << "Введитe количество пар: ";
            cin >> count;
            bitset<sizeof(float)* CHAR_BIT> bits(data.output);
           
        }
        else if (n == 3) {
            cout << "Введитe номер элемента: ";
            cin >> id;
            if (!cin) {
                cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                cin.clear(); // Снимает ошибку
                cin.get();
            }
            while (id < 31 || id > 1) {
                cout << "Попробуйте еще раз! Введитe номер элемента: ";
                cin >> id;
                if (!cin) {
                    cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                    cin.clear(); // Снимает ошибку
                    cin.get();
                }
            }
            cout << "Введитe количество пар: ";
            cin >> count;
            if (!cin) {
                cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                cin.clear(); // Снимает ошибку
                cin.get();
            }
            while (id/2+id%2 < count ) {
                cout << "Попробуйте еще раз! Введитe количество пар: ";
                cin >> count;
                if (!cin) {
                    cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                    cin.clear(); // Снимает ошибку
                    cin.get();
                }
            }
            bitset<sizeof(y)* CHAR_BIT> a1(y);
            cout << "Значение unsigned int до преобразований: " << a1 << endl;
            y = swapUI(y, id, count);
            bitset<sizeof(y)* CHAR_BIT> b1(y);
            cout << "Значение unsigned int после преобразований: " << b1 << endl;
        }
    }

    return 0;
}