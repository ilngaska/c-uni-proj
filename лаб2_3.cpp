#include <iostream>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

double MySqrt(int x)
{
    if (x < 0) return 0; 
    return sqrt((double)x);
}


class CArray_1D {
    int* array; 
    int size;
public:
    void Create_ar1D(int n);       
    void Clear();                  
    void Input_ar1D();             
    void Print_ar1D();             
    void TransformEven_ar1D();     
};

int main()
{
    int size;
    cout << "Enter the size of array:" << endl;
    cin >> size;

    CArray_1D obj;
    obj.Create_ar1D(size);
    obj.Input_ar1D();

    cout << endl << "Initial array:" << endl;
    obj.Print_ar1D();

    obj.TransformEven_ar1D();

    cout << endl << "Array after transforming even elements (sqrt):" << endl;
    obj.Print_ar1D();

    obj.Clear();
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

void CArray_1D::TransformEven_ar1D()
{
    cout << endl << "Transforming even elements to their square roots..." << endl;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0) 
        {
            double root = MySqrt(array[i]);
            cout << "array[" << i << "] = " << array[i]
                 << " -> sqrt = " << root << endl;
            array[i] = (int)root; 
        }
    }
}
