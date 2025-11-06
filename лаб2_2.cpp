#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

class CArray_2D {
    int** array; 
    int rows;
    int cols;
public:
    void Create_ar2D(int r, int c);     
    void Clear();                       
    void Input_ar2D();                  
    void Print_ar2D();                  
    void AvgPositiveCols();            
};

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    CArray_2D obj;
    obj.Create_ar2D(rows, cols);
    obj.Input_ar2D();

    cout << endl << "Initial 2D array:" << endl;
    obj.Print_ar2D();

    obj.AvgPositiveCols();

    obj.Clear();
    system("pause");
    return 0;
}

void CArray_2D::Create_ar2D(int r, int c)
{
    rows = r;
    cols = c;
    array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        array[i] = (int*)malloc(cols * sizeof(int));
}

void CArray_2D::Clear()
{
    for (int i = 0; i < rows; i++)
        free(array[i]);
    free(array);
}

void CArray_2D::Input_ar2D()
{
    cout << endl << "Enter elements of 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "array[" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
    }
}

void CArray_2D::Print_ar2D()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void CArray_2D::AvgPositiveCols()
{
    double* avgArray = (double*)malloc(cols * sizeof(double));

    cout << endl << "Calculating average of positive elements in each column..." << endl;

    for (int j = 0; j < cols; j++) {
        int sum = 0, count = 0;
        for (int i = 0; i < rows; i++) {
            if (array[i][j] > 0) {
                sum += array[i][j];
                count++;
            }
        }
        if (count > 0)
            avgArray[j] = (double)sum / count;
        else
            avgArray[j] = 0; // якщо немає додатних — середнє = 0
    }

    cout << endl << "New 1D array (average positive of each column):" << endl;
    for (int j = 0; j < cols; j++) {
        cout << "avg[" << j << "] = " << avgArray[j] << endl;
    }

    free(avgArray);
}
