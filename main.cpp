#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

unsigned int number1 = 0; // отдельную информацию об ошибках выводить не стал - при неправильном вводе
unsigned int number2 = 1; // программа просто закроется
unsigned int number3 = 2;

class Neuron {
public:
    int Size;
    float *data;
    Neuron(int numb, float (*func)(float *data, int number)){ // конструктор
        this->Size = numb;
        this->data = new float[numb];
        cout << "Enter 'x': " << endl;
        for (int i = 0; i < numb; i++){
            cin >> data[i];
        }
        func(data, numb);
        //cout << "Construction" << endl;
    };

    Neuron(const Neuron &other){                // конструктор копирования
        this->data = new float[other.Size];
        cout << "Enter 'x': " << endl;
        for (int i = 0; i < other.Size; i++){
            cin >> data[i];
        }
    };

    Neuron & operator = (const Neuron &other){ // перегрузка оператора
        this->Size = other.Size;
        this->data = new float[other.Size];
        cout << "Enter 'x': " << endl;
        for (int i = 0; i < other.Size; i++){
            cin >> data[i];
        }
        return *this;
    }

    ~Neuron(){ // деструктор
        delete[] data;
        //cout << "Destruction" << endl;
    };
};

float Foo(float *data, int number){ // функция активации
    float sum;
    for (int i = 0; i < number; i++){ // я не знаю, нужно ли задавать функцию пользователю, поэтому
        sum += data[i];               // в этом примере мы рассматриваем функцию y = x;
    }
    cout << sum << endl;
    return 0;
}

int main()
{
    cout << "Enter amount of 'x': " << endl;
    //int (*pointer)() = Foo;
    cin >> number1;
    Neuron a(number1, Foo);
    Neuron b(number2, Foo);
    Neuron c(number3, Foo);
    b = c = a;
    return 0;
}
