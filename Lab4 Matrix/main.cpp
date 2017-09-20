#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

int main( void ) {
  HANDLE hOutput = (HANDLE)GetStdHandle( STD_OUTPUT_HANDLE );

  COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
  COORD dwBufferCoord = { 0, 0 };
  SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH-1, SCREEN_HEIGHT-1 };

  CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

  ReadConsoleOutput( hOutput, (CHAR_INFO *)buffer, dwBufferSize,
  dwBufferCoord, &rcRegion );

  /*for (int i=0; i<16; i++) {
        buffer[i+5][2].Char.AsciiChar = 'A';
        buffer[i+5][4].Char.AsciiChar = i/10 +48;
        buffer[i+5][5].Char.AsciiChar = i%10 +48;
        buffer[i+5][2].Attributes = i;
  }*/ // 2, 3, 10, 11
  WriteConsoleOutput( hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion );
  return 0;
}
