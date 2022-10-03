#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>


using namespace std;

//Функция очистки консоли 
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

//Функция проверки соответствия string unsigned long int
bool check_UI(string s) {
    for (int i = 0; i < strlen(s.c_str()); i++) {
        if ((isdigit(s[i]) == 0 && i != 0) || (i == 0 && (s[i] != '+' && isdigit(s[i]) == 0))) {
            cout << s[i];
            return 0;
        }

    }
    if (s > "4294967295") {
        return 0;
    }
    return 1;

}


//Функция проверки string float 
bool correct_float(string s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}


int main()
{
    setlocale(LC_ALL, "Russian");// Вывод слов на русском
    int id, count, n = 0, j;
    bool b1, b2;

    union MyUnion
    {
        float input; //sizeof(float) == sizeof(int)
        int   output;
    } data;

    string sf = "a", su = "a";
    unsigned long int y;


    cout << "Введите значение типа float(вввещественное число): ";
   
    do { // Цикл выполняется пока значение float не будет верным(отсутствие букв и других  символов, кроме '.' и цифр) 
        if (sf != "a") {
            cout << "Неверный ввод, попробуйте еще раз: ";
        }
        cin >> sf;
    } while (correct_float(sf) != 1);
    cout << "Верно!\n";

    cout << "Введите значение типа unsigned long int(натуральное число): ";

    do { // Цикл выполняется пока значение unsigned long int не будет верным(отсутствие букв и других символов, кроме знака + на первом месте)
        if (su != "a") {
            cout << "Неверный ввод, попробуйте еще раз: ";
        }
        cin >> su;
        
    } while (check_UI(su) != 1);
    cout << "Верно!" << endl;
    
    y = stoul(su);//Преобразование string в unsigned long int
    data.input = stof(sf);//Преобразование string во Float 
    
    while (n != 6) {
        cout << "0: Вывести битовые значения числа float\n";
        cout << "1: Вывести битовые значения числа unsigned long int\n";
        cout << "2: Поменять местами пары битов в float\n";
        cout << "3: Поменять местами пары битов в unsigned long int\n";
        cout << "4: Ввести значение float\n";
        cout << "5: Ввести значение unsigned long int \n";
        cout << "6: Завершить программу\n" << "Ваше решение:";
        cin >> n;
        if (!cin) {
            Clear();
            cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
            cin.clear(); // Снятие ошибки
            cin.get();
            n = 7;
        }
        while (n < 0 && n>6) {
            cout << "Неверно! попробуйте еще раз: ";
            cin >> n;
            if (!cin) {
                cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                cin.clear(); // Снятие ошибки
                cin.get();
            }
        }
        if (n == 0) {
            Clear();
            //метод по преобразованию float в двоичное предстваление
            bitset<sizeof(float)* CHAR_BIT> bits(data.output);
            cout << "Значение float: " << bits << "\n";
        }
        else if (n == 1) {
            Clear();
            //метод по преобразованию unsigned long  в двоичное предстваление
            bitset<sizeof(y)* CHAR_BIT> a1(y);
            cout << "Значение unsigned int: " << a1 << endl;
        }
        else if (n == 2) {
            cout << "Введитe номер элемента: ";
            cin >> id;
            if (!cin) {
                cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                cin.clear(); // Снимает ошибку
                cin.get();
            }
            while (id > 31 || id < 1) { // Проверка, что номер элемента лежит в соответсвующем диапазоне. Нумерация начинается справа и с нуля 
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
            while (id / 2 + id % 2 < count && count > 0) { // Проверка введенного количества пар на соответствие 
                cout << "Попробуйте еще раз!Максимальное количество пар "<<( id / 2 + id % 2)<<". Введитe количество пар: ";
                cin >> count;
                if (!cin) {
                    cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                    cin.clear(); // Снимает ошибку
                    cin.get();
                }
            }
            Clear();
            bitset<sizeof(float)* CHAR_BIT> bits(data.output);
            cout << "Значение float до преобразований:    " << bits << endl;
            //цикл перестановки пар
            for (int i = id; i > id - count * 2; i -= 2) {
                b1 = bits[i];
                j = i - 1;
                b2 = bits[j];
                bits[j] = b1;//значение битов меняются местами 
                bits[i] = b2;
            }
     
            data.output = bits.to_ullong();
            cout << "Значение float после преобразований: " << bits << endl;

        }
        else if (n == 3) {
            cout << "Введитe номер элемента: ";
            cin >> id;
            if (!cin) {
                cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                cin.clear(); // Снимает ошибку
                cin.get();
            }
            while (id > 31 || id < 1) { // Проверка, что номер элемента лежит в соответсвующем диапазоне. Нумерация начинается справа и с нуля 
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
            while (id / 2 + id % 2 < count && count > 0) {// Проверка соответсвия введенного количества пар
                cout << "Попробуйте еще раз!Максимальное количество пар: "<< (id / 2 + id % 2) <<". Введитe количество пар: ";
                cin >> count;
                if (!cin) {
                    cout << "Ошибка! Введено не число, попробуйте еще раз." << endl;
                    cin.clear(); // Снимает ошибку
                    cin.get();
                }
            }
            Clear();
            bitset<sizeof(y)* CHAR_BIT> a1(y);
            cout << "Значение unsigned long int до преобразований:    " << a1 << endl;

            for (int i = id; i > id - count * 2; i -= 2) {
                b1 = a1[i];
                j = i - 1;
                b2 = a1[j];
                a1[j] = b1;//Замена битов в парах 
                a1[i] = b2;
            }
            y = (unsigned long int)(a1.to_ulong());
            cout << "Значение unsigned long int после преобразований: " << a1 << endl;

        }
        else if (n == 4) {
            cout << "Введите значение типа float(вввещественное число): ";
            cin >> sf;
            while (correct_float(sf) != 1 ){ // Цикл выполняется пока значение float не будет верным(отсутствие букв и других  символов, кроме '.' и цифр) 
                if (sf != "a") {
                    cout << "Неверный ввод, попробуйте еще раз: ";
                }
                cin >> sf;
            }
            cout << "Верно!\n";
            data.input = stof(sf);//Преобразование string во Float 
        }
         else if (n == 5) {
            cin >> su;
            while (check_UI(su) != 1) { // Цикл выполняется пока значение unsigned long int не будет верным(отсутствие букв и других символов, кроме знака + на первом месте)
                if (su != "a") {
                    cout << "Неверный ввод, попробуйте еще раз: ";
                }
                cin >> su;
            } while (check_UI(su) != 1);
            cout << "Верно!" << endl;
            y = stoul(su);//Преобразование string в unsigned long int
         }
    }

    return 0;
}