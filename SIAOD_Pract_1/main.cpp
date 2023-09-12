#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int task_1_1(int n)
{

    int mask = (1 << 7) | (1 << 13) | (1 << 5); // Установка 7, 13 и 5 битов в значение 1
    n |= mask; // Поразрядное ИЛИ

    return n; // Возвращение результата
}

int task_1_2(int n)
{

    int mask = 0x0F; // 00001111 в двоичной системе

    n &= mask; // Применяем поразрядную операцию И с маской

    return n; // Возвращение результата
}

int task_1_3(int n)
{
     n <<= 9; // 512 = 2^9 Умножение на 512 с помощью поразрядной операции сдвига влево

     return n; // Возвращение результата
}

int task_1_4(int n)
{
    n >>= 7; // 128 = 2^7 Деление на 128 с помощью поразрядной операции сдвига вправо

    return n; // Возвращение результата
}

int task_1_5(int value, int n)
{
    int mask = 1 << n; // Создаем маску, установив n-ый бит в 1

     value |= mask; // Применяем поразрядную операцию "ИЛИ" с маской

     return value;

}

const int MAX_NUM = 10000; // Максимальное количество чисел
const int MEMORY_LIMIT = 1024 * 1024; // 1 МБ - лимит памяти


int main() {

    setlocale(LC_ALL, "Russian");

    int n;     // Определение переменной целого типа
    n = 0x3A;  // Присваивание значения в шестнадцатеричной системе счисления
    cout << bitset<sizeof(int) * 4 >(task_1_1(n)) << endl;

    cin >> n;
    cout << bitset<sizeof(int) * 4>(task_1_2(n)) << endl;

    cin >> n;
    cout << bitset<sizeof(int) * 4>(task_1_3(n)) << endl;

    cin >> n;
    cout << bitset<sizeof(int) * 4>(task_1_4(n)) << endl;

    int value;
    cout << "input format: value, n" << endl;
    cin >> value >> n;
    cout << bitset<sizeof(int) * 4>(task_1_5(value,n)) << endl;



    vector<int> numbers;
    unsigned char bitArray = 0; // Инициализация битового массива нулями

    cout << "Введите до 8 чисел (0-7), завершите ввод с -1:" << endl;
    while (cin >> n)
    {
        if (n == -1) break;

        if (n >= 0 && n <= 7)
        {
            numbers.push_back(n);
            bitArray |= (1 << n);
        }
        else cout << "Число должно быть в диапазоне от 0 до 7. Попробуйте снова: ";
    }


     cout << bitset<sizeof(int) * 4>(bitArray) << endl;


    for (int i = 0; i <= 7; ++i) {
        if ((bitArray & (1 << i)) != 0)
        {
            cout << i << " ";
        }
    }

    
    ifstream inputFile("C://Users//Елена//Desktop//ВУЗ//СИАОД//Практическая работа 1//input.txt");
    ofstream outputFile("C://Users//Елена//Desktop//ВУЗ//СИАОД//Практическая работа 1//output.txt");

    vector<int> bitArray2(MAX_NUM+1,0);

    while (inputFile >> n) {bitArray2[n] = 1;} // Считывает числа

    for (int i = 0; i <= MAX_NUM; i++) {
        if ((bitArray2[i]==1))
        {
            outputFile << i << "\n"; // Записываем числа в отсортированном порядке
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Сортировка завершена.";


    return 0;
}