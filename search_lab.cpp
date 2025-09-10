#include <iostream>
#include <string>
#include <ctime> // Для time() та clock()

using namespace std;

// Максимальна довжина шаблону для статичного масиву
const int MAX_PATTERN_LENGTH = 100;

// Функція для попередньої обробки шаблону (LPS для КМП)
void computeLPS(const string& pattern, int lps[]) {
    int m = pattern.size();
    int len = 0;  
    lps[0] = 0;   

    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
        } else {
            lps[i] = 0;
        }
    }
}

// Функція КМП для пошуку шаблону в тексті
int KMP(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int lps[MAX_PATTERN_LENGTH]; // Масив LPS для шаблону
    computeLPS(pattern, lps);
    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; // Повертаємо позицію
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1; // Якщо не знайдено
}

// Функція для прямого пошуку шаблону в тексті
int directSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // Повертаємо позицію
        }
    }
    return -1; // Якщо не знайдено
}

int main() {
    string text = "Lorem Ipsum is simply dummy text of the printing and typesetting industry."; // Текст для пошуку
    string pattern = "text"; // Шаблон

    // Прямий пошук
    clock_t start = clock();
    int directIndex = directSearch(text, pattern);
    clock_t end = clock();
    double directDuration = double(end - start) / CLOCKS_PER_SEC * 1000;

    // КМП пошук
    start = clock();
    int kmpIndex = KMP(text, pattern);
    end = clock();
    double kmpDuration = double(end - start) / CLOCKS_PER_SEC * 1000;

    // Вивід результатів
    cout << "Результати пошуку:" << endl;
    cout << "Прямий пошук: позиція = " << directIndex << ", час = " << directDuration << " мс" << endl;
    cout << "КМП пошук: позиція = " << kmpIndex << ", час = " << kmpDuration << " мс" << endl;

    return 0;
}
