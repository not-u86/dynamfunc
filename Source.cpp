#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


void createArray(int*& ptr, int size)
{

    ptr = new int[size];
}


void fillArray(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 100;
    }
}


void printArray(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}


void deleteArray(int*& ptr)
{
    delete[] ptr;
    ptr = nullptr;
}


void addElement(int*& ptr, int& size, int element)
{
    int* temp = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = ptr[i];
    }

    temp[size] = element;

    delete[] ptr;

    ptr = temp;
    size++;
}


void insertElement(int*& ptr, int& size, int index, int element)
{
    if (index < 0 || index > size)
    {
        cout << "неверно" << endl;
        return;
    }

    int* temp = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = ptr[i];
    }

    temp[index] = element;

    for (int i = index; i < size; i++)
    {
        temp[i + 1] = ptr[i];
    }

    delete[] ptr;

    ptr = temp;
    size++;
}


void removeElement(int*& ptr, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        cout << "неверно" << endl;
        return;
    }

    int* temp = new int[size - 1];

    for (int i = 0; i < index; i++)
    {
        temp[i] = ptr[i];
    }

    for (int i = index + 1; i < size; i++)
    {
        temp[i - 1] = ptr[i];
    }

    delete[] ptr;

    ptr = temp;
    size--;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0));

    int size = 5;
    int* ptr = nullptr;

    createArray(ptr, size);

    fillArray(ptr, size);

    cout << "массив: ";
    printArray(ptr, size);

    addElement(ptr, size, 50);

    cout << "добавление: ";
    printArray(ptr, size);

    insertElement(ptr, size, 2, 99);

    cout << "вставка: ";
    printArray(ptr, size);

    removeElement(ptr, size, 1);

    cout << "удалени: ";
    printArray(ptr, size);

    deleteArray(ptr);

    return 0;
}