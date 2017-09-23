#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int y = -1; y < 16; y++) {
        for(int x = -1; x < 16; x++) {
            SetConsoleCursorPosition(console, {(x + 1) * 4, y + 1});
            SetConsoleTextAttribute(console, 15);
            cout << (char)186;
            if(y == -1)
                cout << x;
            else if(x == -1)
                cout << y;
            else {
                SetConsoleTextAttribute(console, y + x * 16);
                cout << (char)(254) << (char)(254) << (char)(254);
            }
        }
        SetConsoleCursorPosition(console, {68, y + 1});
        SetConsoleTextAttribute(console, 15);
        cout << (char)186 << endl;
    }
    for(int y = -1; y < 16; y++) {
        for(int x = -1; x < 16; x++) {
            int c = y * 16 + x;
            SetConsoleCursorPosition(console, {(x + 1) * 4, y + 19});
            cout << (char)186;
            SetConsoleCursorPosition(console, {(x + 1) * 4 + 2, y + 19});
            if(y == -1)
                cout << x;
            else if(x == -1)
                cout << y;
            else {
                if(32 <= c && c <= 126)
                    SetConsoleTextAttribute(console, 143);
                if(c != 146)
                    cout << (char)c;
                else {
                    SetConsoleTextAttribute(console, 79);
                    cout << (char)(146);
                }
                SetConsoleTextAttribute(console, 15);
            }
        }
        SetConsoleCursorPosition(console, {68, y + 19});
        cout << (char)186 << endl;
    }
    SetConsoleTextAttribute(console, 143);
    SetConsoleCursorPosition(console, {0, 40});
    for(int y = 0; y < 16; y++) {
        for(int x = 0; x < 16; x++)
            cout << (char)(y * 16 + x);
        cout << endl;
    }
    SetConsoleTextAttribute(console, 15);
    cout << endl << "Done" << endl;
}
