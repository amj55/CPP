#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main ( int argc, char *argv[] ) {
    ofstream file;
    file.open ("C:\\Users\\Gaelin\\CPP\\usoclient\\#files\\UsoClient.exe.log", ios::out | ios::app);
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    file << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday << ' '
         << (now->tm_hour) << ':'
         << (now->tm_min) << ':'
         << (now->tm_sec) << ' ';
    for (int i=0; i<argc; i++)
        file << argv[i] << " ";
    file << endl;
    file.close();
    return 0;
}
