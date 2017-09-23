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
#define RATE_LIMIT 240


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
    int rate = 175;
    std::string message = "The matrix";
    CHAR_INFO tempBuffer[message.length()];
    bool isChar[message.length()];
    for(int i = 0; i < message.length(); i++) isChar[i] = false;
    while(true) {
        for(r = SCREEN_HEIGHT - 1; r >= 0; r--) {
            for(c = 0; c < SCREEN_WIDTH; c++) {
                if(r == 0) {
                    if(buffer[r][c].Char.AsciiChar == 32) {
                        if(rand() % (RATE_LIMIT + 25 - rate) == 0)
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
                    // ≡ = 240; ♥ = 3, ║ = 186;
                    buffer[r][c].Char.AsciiChar =
                        rand() % 256;
                    //(buffer[r + 1][c].Char.AsciiChar == 32) ? 86 : 186;
                    //240; // ≡
                    //3;   // ♥
                }
            }
        }
        if(rate < RATE_LIMIT) rate++;
        if(rate < 100) rate += 2;
        if(rate == RATE_LIMIT)
            for(int i = message.length() - 1; i >= 0; i--) {
                /*if(!isChar[i]) {
                    if(i == 0 | isChar[i - 1])
                        if(buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (message.length() / 2) + i].Char.AsciiChar ==
                                message[i])
                            isChar[i] = true;
                } else {*/
                tempBuffer[i] = buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (message.length() / 2) + i];
                buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (message.length() / 2) + i].Char.AsciiChar =
                    message[i];
                buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (message.length() / 2) + i].Attributes = COLOR1;
                //}
            }
        WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
        if(rate == RATE_LIMIT)
            for(int i = 0; i < message.length(); i++)
                //if(isChar[i])
                buffer[SCREEN_HEIGHT / 2][SCREEN_WIDTH / 2 - (message.length() / 2) + i] = tempBuffer[i];
        Sleep(250 - rate);
    }
    return 0;
}
