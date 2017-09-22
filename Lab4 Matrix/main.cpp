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
#define COLOR2 2  //4
#define COLOR1 10 //12


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

    /*for (int i=0; i<16; i++) {
      buffer[i+5][2].Char.AsciiChar = 'A';
      buffer[i+5][4].Char.AsciiChar = i/10 +48;
      buffer[i+5][5].Char.AsciiChar = i%10 +48;
      buffer[i+5][2].Attributes = i;
    } // 2, 3, 10, 11   33-126   -128 -1
    WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
    Sleep(10000);*/
    ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
    int rate = 175;
    std::string text = "The matrix";
    CHAR_INFO tempBuffer[text.length()];
    while(true) {
        for(r = SCREEN_HEIGHT - 1; r >= 0; r--) {
            for(c = 0; c < SCREEN_WIDTH; c++) {
                if(r == 0) {
                    if(buffer[r][c].Char.AsciiChar == 32) {
                        if(rand() % (250 - rate) == 0)
                            buffer[r][c].Char.AsciiChar = 31;
                    } else {
                        if(rand() % 5 == 0)
                            buffer[r][c].Char.AsciiChar = 32;
                    }
                    //buffer[r][1].Char.AsciiChar = (rate/100) % 10 + 48;
                    //buffer[r][2].Char.AsciiChar = (rate/10) % 10 + 48;
                    //buffer[r][3].Char.AsciiChar = rate % 10 + 48;
                } else
                    buffer[r][c] = buffer[r - 1][c];
                if(!(buffer[r][c].Char.AsciiChar == 32)) {
                    buffer[r][c].Attributes = (buffer[r + 1][c].Char.AsciiChar == 32) ? COLOR1 : COLOR2;
                    // ≡ = 240; ♥ = 3;
                    buffer[r][c].Char.AsciiChar = rand() % 256;
                }
            }
        }
        if(rate < 230) rate++;
        if(rate < 100) rate += 2;
        if(rate == 230)
            for(int i = 0; i < text.length(); i++) {
                tempBuffer[i] = buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (text.length() / 2) + i];
                buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (text.length() / 2) + i].Char.AsciiChar = text[i];
                buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (text.length() / 2) + i].Attributes = COLOR1;
            }
        WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
        if(rate == 230)
            for(int i = 0; i < text.length(); i++)
                buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (text.length() / 2) + i] = tempBuffer[i];
        Sleep(250 - rate);
    }
    return 0;
}
