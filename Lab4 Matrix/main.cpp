#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 125
#define SCREEN_HEIGHT 30


int main(void) {
    int c = 0;
    int r = 0;
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

    CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

    ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
    /*for (int i=0; i<16; i++) {
      buffer[i+5][2].Char.AsciiChar = 'A';
      buffer[i+5][4].Char.AsciiChar = i/10 +48;
      buffer[i+5][5].Char.AsciiChar = i%10 +48;
      buffer[i+5][2].Attributes = i;
    }*/ // 2, 3, 10, 11
    while(true) {
        SetConsoleTextAttribute(hOutput, 2);
        for(r = 0; r < SCREEN_HEIGHT; r++) {
            for(c = 0; c < SCREEN_WIDTH; c++) {
                if(r == 0) {
                    if((rand() % 3 + 1) % 2 == 0) {
                        buffer[r][c].Char.AsciiChar = rand() % 74 + 48;
                        buffer[r][c].Attributes = rand() % 2 + 10;
                    }
                } else
                    buffer[r][c] = buffer [r - 1][c];
                }
            WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
            Sleep(100);
        }


        for(r = 0; r < SCREEN_HEIGHT; r++) {
            for(c = 0; c < SCREEN_WIDTH; c++) {
                buffer[r][c].Char.AsciiChar = ' ';
            }
        }
    }
    return 0;
}








