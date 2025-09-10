#include <iostream>
#include <cstdlib> // для rand() і srand()
#include <ctime>   // для time() та clock()

using namespace std;

// Генерація випадкового масиву
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // числа від 0 до 1000
    }
}

// Лінійний пошук
int linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Бінарний пошук (передбачає, що масив вже відсортований)
int binarySearch(const int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Простий вибір для сортування масиву для бінарного пошуку
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[  i], arr[minIndex]);
    }
}

int main() {
    const int n = 50000;
    int arr[n];
    int key = 5; // Значення, яке будемо шукати

    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел

    // Випадковий масив для лінійного пошуку
    generateArray(arr, n);
    clock_t start = clock();
    int linearIndex = linearSearch(arr, n, key);
    clock_t end = clock();
    double linearDuration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Лінійний пошук завершено за: " << linearDuration << " мс, індекс: " << linearIndex << endl;

    // Сортування масиву для бінарного пошуку
    selectionSort(arr, n);

    // Бінарний пошук на відсортованому масиві
    start = clock();
    int binaryIndex = binarySearch(arr, n, key);
    end = clock();
    double binaryDuration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Бінарний пошук завершено за: " << binaryDuration << " мс, індекс: " << binaryIndex << endl;

    return 0;
}
