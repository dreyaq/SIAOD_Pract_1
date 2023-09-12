#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int task_1_1(int n)
{

    int mask = (1 << 7) | (1 << 13) | (1 << 5); // ��������� 7, 13 � 5 ����� � �������� 1
    n |= mask; // ����������� ���

    return n; // ����������� ����������
}

int task_1_2(int n)
{

    int mask = 0x0F; // 00001111 � �������� �������

    n &= mask; // ��������� ����������� �������� � � ������

    return n; // ����������� ����������
}

int task_1_3(int n)
{
     n <<= 9; // 512 = 2^9 ��������� �� 512 � ������� ����������� �������� ������ �����

     return n; // ����������� ����������
}

int task_1_4(int n)
{
    n >>= 7; // 128 = 2^7 ������� �� 128 � ������� ����������� �������� ������ ������

    return n; // ����������� ����������
}

int task_1_5(int value, int n)
{
    int mask = 1 << n; // ������� �����, ��������� n-�� ��� � 1

     value |= mask; // ��������� ����������� �������� "���" � ������

     return value;

}

const int MAX_NUM = 10000; // ������������ ���������� �����
const int MEMORY_LIMIT = 1024 * 1024; // 1 �� - ����� ������


int main() {

    setlocale(LC_ALL, "Russian");

    int n;     // ����������� ���������� ������ ����
    n = 0x3A;  // ������������ �������� � ����������������� ������� ���������
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
    unsigned char bitArray = 0; // ������������� �������� ������� ������

    cout << "������� �� 8 ����� (0-7), ��������� ���� � -1:" << endl;
    while (cin >> n)
    {
        if (n == -1) break;

        if (n >= 0 && n <= 7)
        {
            numbers.push_back(n);
            bitArray |= (1 << n);
        }
        else cout << "����� ������ ���� � ��������� �� 0 �� 7. ���������� �����: ";
    }


     cout << bitset<sizeof(int) * 4>(bitArray) << endl;


    for (int i = 0; i <= 7; ++i) {
        if ((bitArray & (1 << i)) != 0)
        {
            cout << i << " ";
        }
    }

    
    ifstream inputFile("C://Users//�����//Desktop//���//�����//������������ ������ 1//input.txt");
    ofstream outputFile("C://Users//�����//Desktop//���//�����//������������ ������ 1//output.txt");

    vector<int> bitArray2(MAX_NUM+1,0);

    while (inputFile >> n) {bitArray2[n] = 1;} // ��������� �����

    for (int i = 0; i <= MAX_NUM; i++) {
        if ((bitArray2[i]==1))
        {
            outputFile << i << "\n"; // ���������� ����� � ��������������� �������
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "���������� ���������.";


    return 0;
}