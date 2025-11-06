#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CInsertText {
    string filename;
    string content;
    string insertStr;
    int position;

public:
    CInsertText(const string& fname) : filename(fname) {}

    void Processing() {
        if (!readFile()) {
            cout << "Can't read file!" << endl;
            return;
        }

        cout << "\nCurrent file content:\n" << content << endl;

        // Вводимо рядок для вставки
        cout << "\nEnter string to insert: ";
        getline(cin, insertStr);

        // Вводимо позицію як рядок, потім конвертуємо у число
        string posStr;
        cout << "Enter position (0 to " << content.length() << "): ";
        getline(cin, posStr);

        try {
            position = stoi(posStr);
        } catch (...) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position < 0 || position > (int)content.length()) {
            cout << "Invalid position!" << endl;
            return;
        }

        // Вставка рядка у вказану позицію
        content.insert(position, insertStr);

        if (writeFile()) {
            cout << "\nNew file content:\n" << content << endl;
        } else {
            cout << "Error writing to file!" << endl;
        }
    }

private:
    bool readFile() {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) return false;
        content.assign((istreambuf_iterator<char>(file)),
                       istreambuf_iterator<char>());
        file.close();
        return true;
    }

    bool writeFile() {
        ofstream file(filename, ios::binary);
        if (!file.is_open()) return false;
        file << content;
        file.close();
        return true;
    }
};

int main() {
    string filename = "lab3_1.txt";
    CInsertText obj(filename);
    obj.Processing();
    return 0;
}
