#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    size = 0;
    data = nullptr;
}

DynamicArray::DynamicArray(int size)
{
    this->size = size;
    data = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

DynamicArray::~DynamicArray()
{
    delete[] data;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this == &other) return *this;

    delete[] data;

    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;
}

void DynamicArray::FillRandom()
{
    static int seed = 17;
    for (int i = 0; i < size; i++)
    {
        seed = (seed * 37 + 13) % 100;
        data[i] = seed;
    }
}

void DynamicArray::Print() const
{
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void DynamicArray::Reverse()
{
    for (int i = 0; i < size / 2; i++)
    {
        int t = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = t;
    }
}

void DynamicArray::Sort()
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (data[j] > data[j + 1])
            {
                int t = data[j];
                data[j] = data[j + 1];
                data[j + 1] = t;
            }
}

int DynamicArray::Search(int value) const
{
    for (int i = 0; i < size; i++)
        if (data[i] == value) return i;
    return -1;
}

void DynamicArray::Resize(int newSize)
{
    if (newSize < 0) return;

    int* newData = new int[newSize];
    int m = newSize < size ? newSize : size;

    for (int i = 0; i < m; i++)
        newData[i] = data[i];

    for (int i = m; i < newSize; i++)
        newData[i] = 0;

    delete[] data;
    data = newData;
    size = newSize;
}

DynamicArray DynamicArray::operator+(int value) const
{
    DynamicArray r(size + value);
    for (int i = 0; i < size; i++) r.data[i] = data[i];
    for (int i = size; i < size + value; i++) r.data[i] = 0;
    return r;
}

DynamicArray DynamicArray::operator-(int value) const
{
    if (size <= value) return DynamicArray(0);

    DynamicArray r(size - value);
    for (int i = 0; i < r.size; i++)
        r.data[i] = data[i];

    return r;
}

DynamicArray DynamicArray::operator*(int value) const
{
    DynamicArray r(size);
    for (int i = 0; i < size; i++)
        r.data[i] = data[i] * value;
    return r;
}

DynamicArray DynamicArray::operator-(const DynamicArray& other) const
{
    int newSize = size < other.size ? size : other.size;
    DynamicArray r(newSize);
    for (int i = 0; i < newSize; i++)
        r.data[i] = data[i] - other.data[i];
    return r;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) const
{
    DynamicArray r(size + other.size);
    for (int i = 0; i < size; i++)
        r.data[i] = data[i];
    for (int i = 0; i < other.size; i++)
        r.data[size + i] = other.data[i];
    return r;
}

DynamicArray& DynamicArray::operator++()
{
    Resize(size + 1);
    return *this;
}

DynamicArray& DynamicArray::operator--()
{
    if (size > 0) Resize(size - 1);
    return *this;
}
