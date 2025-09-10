#include <iostream>
#include <string>

using namespace std;

string caesarCipher(const string& text, int shift) {
    string result = "";
    
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    
    return result;
}

int main() {
    string text;
    int shift;
    char mode;
    
    cout << "Введіть текст: ";
    getline(cin, text);
    
    cout << "Введіть ключ (зміщення): ";
    cin >> shift;
    
    cout << "Виберіть режим (e для шифрування, d для дешифрування): ";
    cin >> mode;
    
    shift = (mode == 'd') ? -shift : shift;  // Вибір шифрування або дешифрування
    
    cout << "Результат: " << caesarCipher(text, shift) << endl;
    
    return 0;
}
