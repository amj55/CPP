
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
    bool bug1 = true, bug2 = true;
    int bug1Color = 11, bug2Color = 9, bug2Grow = 10, colideColor = 12;

    for(i = 0, j = 80; j > 0; i++, j--) {
        if(bug1) {
            SetConsoleTextAttribute(con, bug1Color);
            coord = {i, 10};
            SetConsoleCursorPosition(con, coord);
            printf(ben[i % 4]);
            coord.Y = 11;
            SetConsoleCursorPosition(con, coord);
            printf(" -0000:");
            coord.Y = 12;
            SetConsoleCursorPosition(con, coord);
            printf(ben[i % 4]);
        }
        if(bug2) {
            SetConsoleTextAttribute(con, bug2Color);
            coord.X = j;
            if(i ==  37) SetConsoleTextAttribute(con, bug2Grow);
            if(!bug1) {
                coord.Y = 9;
                SetConsoleCursorPosition(con, coord);
                printf(ben[i % 4]);
            }
            coord.Y = 10;
            SetConsoleCursorPosition(con, coord);
            printf((bug1) ? ben[i % 4] : " :0000-");
            coord.Y = 11;
            SetConsoleCursorPosition(con, coord);
            if(i ==  37) SetConsoleTextAttribute(con, bug2Color);
            printf(":00000-");
            coord.Y = 12;
            SetConsoleCursorPosition(con, coord);
            if(i ==  37) SetConsoleTextAttribute(con, bug2Grow);
            printf((bug1) ? ben[i % 4] : " :0000-");
            if(!bug1) {
                coord.Y = 13;
                SetConsoleCursorPosition(con, coord);
                printf(ben[i % 4]);
            }
        }
        Sleep(75);
        if(i == 36 | i == 37) {
            SetConsoleTextAttribute(con, colideColor);
            coord = {i, 11};
            SetConsoleCursorPosition(con, coord);
            printf("***");
            Sleep(100);
            bug1 = false;
        }

        system("cls");
    }

    SetConsoleTextAttribute(con, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
