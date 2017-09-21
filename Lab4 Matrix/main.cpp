/*
*
* Created by Gaelin Shupe.
*
* Matrix
*
*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//#define SCREEN_WIDTH 125
//#define SCREEN_HEIGHT 30
#define SCREEN_WIDTH 197
#define SCREEN_HEIGHT 51


int main(void) {
    system("mode 650");
    Sleep(1000);
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
    }*/ // 2, 3, 10, 11   33-126   -128 -1
    /*for(char c = 1; c != 0; c++) {
            std::cout << (int)c << "  " << c << std::endl;
    }
    std::cout << "Done" << std::endl;
    Sleep(1000000);*/
    int rate = 0;
    while(true) {
        for(r = SCREEN_HEIGHT - 1; r >= 0; r--) {
            for(c = 0; c < SCREEN_WIDTH; c++) {
                if(r == 0) {
                    if(buffer[r][c].Char.AsciiChar == 32) {
                        if(rand() % (250 - rate) == 0) {
                            buffer[r][c].Char.AsciiChar = 31;
                            buffer[r][c].Attributes = 2;
                        }
                    } else {
                        if(rand() % 5 == 0) {
                            buffer[r][c].Char.AsciiChar = 32;
                        }
                    }
                    //buffer[r][1].Char.AsciiChar = (rate/100) % 10 + 48;
                    //buffer[r][2].Char.AsciiChar = (rate/10) % 10 + 48;
                    //buffer[r][3].Char.AsciiChar = rate % 10 + 48;
                } else {
                    buffer[r][c] = buffer[r - 1][c];
                    //WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
                    if(!(buffer[r][c].Char.AsciiChar == 32)) {
                        // ≡ = 240; ♥ = 3;
                        if(buffer[r + 1][c].Char.AsciiChar == 32) {
                            buffer[r][c].Attributes = 10;
                        } else {
                            buffer[r][c].Attributes = 2;
                        }
                    }
                }
                if(!(buffer[r][c].Char.AsciiChar == 32))
                    buffer[r][c].Char.AsciiChar = rand() % 256;
            }
        }
        if(rate < 240) rate++;
        if(rate < 100) rate++;
        WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
        Sleep(250 - rate);


        /*for(r = 0; r < SCREEN_HEIGHT; r++)
            for(c = 0; c < SCREEN_WIDTH; c++)
                buffer[r][c].Char.AsciiChar = 32;*/
    }
    return 0;
}
