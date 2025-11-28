#include <iostream>
using namespace std;
#include "DynamicArray.h"

DynamicArray CreateArray()
{
    DynamicArray a(5);
    a.FillRandom();
    return a;
}

int main()
{
    DynamicArray a = CreateArray();
    DynamicArray b = CreateArray();

    cout << "A: ";
    a.Print();

    cout << "B: ";
    b.Print();

    cout << "A + 10: ";
    (a + 10).Print();

    cout << "A - 2: ";
    (a - 2).Print();

    cout << "A * 2: ";
    (a * 2).Print();

    cout << "A - B: ";
    (a - b).Print();

    cout << "A + B: ";
    (a + b).Print();

    ++a;
    cout << "++A: ";
    a.Print();

    --a;
    cout << "--A: ";
    a.Print();

    return 0;
}
