
#include <iostream>
#include <typeinfo>
#include <locale.h>


using namespace std;

template <class T>
class Massiv {
private:

    T* massiv = new T;
    int N;
    T m_value;
public:

    Massiv() {
        int N = 0;
        T* massiv = NULL;
    }

    Massiv(T value)
    {
        m_value = value;
    }

    ~Massiv()
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
    Massiv(const Massiv<T>& a) {
        this->N = a.n;
        this->massiv = new T[N];
        for (int i = 0; i < N; i++) {
            this->massiv[i] = a.massive[i];
        }
    }

    Massiv(T* massive, int n) {
        this->N = n;
        massiv = new T[N];
        for (int i = 0; i < N; i++) {
            this->massiv[i] = massive[i];
        }
    }

    void add() {

        this->N += 1;
        cout << endl << "Vvedite element: ";
        cin >> massiv[N - 1];

    }

    void del() {
        cout << endl << "Vvedite index: ";
        int index;
        cin >> index;
        T* arr = new T[N];
        for (int i = 0; i < N; i++) {
            arr[i] = massiv[i];
        }
        this->N = N - 1;
        T* massiv = new T[N];
        int i = 0;
        for (int g = 0; g < index; g++) {
            massiv[i] = arr[g];
            i++;
        }
        for (int g = index + 1; g <= N; g++) {
            this->massiv[i] = arr[g];
            i++;
        }
    }


    void sortirovka() {
        T temp;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (massiv[i] > massiv[j])
                {
                    temp = massiv[i];
                    massiv[i] = massiv[j];
                    massiv[j] = temp;
                }
            }
        }
    }

    void Print() {
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout  << i << "element = " << massiv[i] << endl;
        }
    }

};


template <>
Massiv<char*>::Massiv(char* value)
{
    int length = 0;
    while (value[length] != '\0')
        ++length;
    ++length;
    m_value = new char[length];
    for (int count = 0; count < length; ++count)
        m_value[count] = value[count];
}
template <>
Massiv<char*>::~Massiv()
{
    delete[] m_value;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    cout << "Kolichestvo elementov: ";
    cin >> n;

    int* msint = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] element = ";
        cin >> msint[i];
    }
    Massiv<int> arr(msint, n);


    int number = 0;
    do {
        cout << "================" << endl;
        cout << endl << endl << "\t\tMenu" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Show" << endl;
        cout << "4. Sortirovka po vozrastaniy" << endl;
        cout << "0. End" << endl;
        cout << "================" << endl;

        cin >> number;

        switch (number) {
        case 1:
            arr.add();
            break;
        case 2:
            arr.del();
            break;
        case 3:
            arr.Print();
            break;
        case 4:
            arr.sortirovka();
            break;
        }

    } while (number != 0);

    system("pause");
    char* string = new char[40];

    // Просим пользователя ввести свое имя
    std::cout << "Enter your name: ";
    std::cin >> string;

    // Сохраняем то, что ввел пользователь
    Massiv<char*> Massiv(string);

    // Удаляем временную строку
    delete[] string;

    // Пытаемся вывести то, что ввел пользователь
    Massiv.print();
}