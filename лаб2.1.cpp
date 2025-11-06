#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

class CArray_1D {
    int* array; 
    int size;
public:
    void Create_ar1D(int n);      
    void Clear();                 
    void Input_ar1D();            
    void Print_ar1D();            
    void SortDescending_ar1D();   
};

int main()
{
    int size;
    cout << "Enter the size of array:" << endl;
    cin >> size;

    CArray_1D obj1;
    obj1.Create_ar1D(size);
    obj1.Input_ar1D();

    cout << endl << "Initial array:" << endl;
    obj1.Print_ar1D();

    obj1.SortDescending_ar1D();

    cout << endl << "Array after bubble sort (descending):" << endl;
    obj1.Print_ar1D();

    obj1.Clear();
    system("pause");
    return 0;
}

void CArray_1D::Create_ar1D(int n)
{
    size = n;
    array = (int*)malloc(size * sizeof(int)); 
}

void CArray_1D::Clear()
{
    free(array); 
}

void CArray_1D::Input_ar1D()
{
    cout << endl << "Enter numbers of array:" << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }
}

void CArray_1D::Print_ar1D()
{
    for (int i = 0; i < size; i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }
}

void CArray_1D::SortDescending_ar1D()
{
    cout << endl << "Sorting array in descending order (bubble sort)..." << endl;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
