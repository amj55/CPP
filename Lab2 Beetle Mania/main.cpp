
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
    bool bug1=true, bug2=true;

    for (i=0, j=80; j>0; i++, j--) {
        if (bug1) {
            SetConsoleTextAttribute(con, 3 | FOREGROUND_INTENSITY);
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
        }
        if (bug2) {
            SetConsoleTextAttribute(con, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            coord.X = j;
            coord.Y = 9;
            SetConsoleCursorPosition(con, coord);
            printf(ben[i%4]);
            coord.Y = 10;
            SetConsoleCursorPosition(con, coord);
            printf(" :0000-");
            coord.Y = 11;
            SetConsoleCursorPosition(con, coord);
            printf(":00000-");
            coord.Y = 12;
            SetConsoleCursorPosition(con, coord);
            printf(" :0000-");
            coord.Y = 13;
            SetConsoleCursorPosition(con, coord);
            printf(ben[i%4]);
        }
        Sleep(75);
        if (i==36 | i==37) {
            SetConsoleTextAttribute(con, FOREGROUND_RED | FOREGROUND_INTENSITY);
            coord.Y = 11;
            coord.X = i;
            SetConsoleCursorPosition(con, coord);
            printf("***");
            Sleep(100);
            bug1=false;
        }

        system("cls");
    }

    SetConsoleTextAttribute(con, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
