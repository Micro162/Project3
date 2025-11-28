#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* data;
    int size;

public:
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    void FillRandom();
    void Print() const;
    void Reverse();
    void Sort();
    int Search(int value) const;
    void Resize(int newSize);

    DynamicArray operator+(int value) const;
    DynamicArray operator-(int value) const;
    DynamicArray operator*(int value) const;
    DynamicArray operator-(const DynamicArray& other) const;
    DynamicArray operator+(const DynamicArray& other) const;

    DynamicArray& operator++();
    DynamicArray& operator--();
};
