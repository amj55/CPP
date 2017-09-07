
/**
* Beetle Mania
*
* This is a small windows console text animation
* It shows how to wright colored text and how to
* put text at a fixed position in a console.
**/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

const char *const ben[] = {
    "  )))",
    "  |||",
    "  (((",
    "  |||"
};

int main() {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j;
    COORD coord;
    coord.X=0;
    COORD coords[6];

    for (i=0, j=80; i<40; i++, j--) {
        SetConsoleTextAttribute(con, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        coord.X = i;
        coord.Y = 10;
        SetConsoleCursorPosition(con, coord);
        printf(ben[i%4]);
        coord.Y = 11;
        SetConsoleCursorPosition(con, coord);
        printf(" -0000:");
        coord.Y = 12;
        SetConsoleCursorPosition(con, coord);
        printf(ben[i%4]);

        Sleep(75);
        if (i == 39) {
            SetConsoleTextAttribute(con, FOREGROUND_RED | FOREGROUND_INTENSITY);
            coord.Y = 11;
            coord.X = j+2;
            SetConsoleCursorPosition(con, coord);
            printf("***");
            Sleep(2000);
        }

        system("cls");
    }

    SetConsoleTextAttribute(con, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
