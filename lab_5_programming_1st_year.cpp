#include <iostream>
using namespace std;

#define WIDTH 3
#define LENGTH 4

void transpose(const int input[][LENGTH], int output[][WIDTH]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            output[j][i] = input[i][j];
        }
    }
}

int main() {
    int i[WIDTH][LENGTH] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int o[LENGTH][WIDTH];

    transpose(i, o);
    
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << o[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
