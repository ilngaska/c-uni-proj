#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define F1 "/home/markie/lab3_2/lab3_2.bin"
#define F2 "lab3_2_copy.bin"

class CCopyBin {
    FILE* f1;
    FILE* f2;
    char buf[256];
    int pos;
    int n;

public:
    CCopyBin() {
        f1 = fopen(F1, "rb");
        if (!f1) {
            cout << "File " << F1 << " doesn't exist. Generating a new binary file" << endl;
            GenerateBinaryFile();
            f1 = fopen(F1, "rb");
            if (!f1) {
                cout << "Error" << F1 << endl;
                exit(1);
            }
        }

        f2 = fopen(F2, "wb");
        if (!f2) {
            cout << "Error" << F2 << endl;
            fclose(f1);
            exit(1);
        }
    }

    ~CCopyBin() {
        fclose(f1);
        fclose(f2);
    }

    void GenerateBinaryFile() {
        srand(time(0));
        FILE* f = fopen(F1, "wb");
        if (!f) {
            cout << "Error" << endl;
            exit(1);
        }

        for (int i = 0; i < 512; i++) {
            unsigned char byte = rand() % 256;
            fwrite(&byte, sizeof(byte), 1, f);
        }

        fclose(f);
        cout << "Binary file " << F1 << " created (512 bytes)." << endl;
    }

    void Processing() {
        cout << "Enter position: ";
        cin >> pos;
        cout << "Enter quantity: ";
        cin >> n;

        fseek(f1, pos, SEEK_SET);

        int readBytes = fread(buf, sizeof(char), n, f1);
        fwrite(buf, sizeof(char), readBytes, f2);

        cout << "\nCopied " << readBytes << " bytes from position " << pos
             << " to file " << F2 << endl;
    }
};

int main() {
    CCopyBin obj;
    obj.Processing();
    return 0;
}