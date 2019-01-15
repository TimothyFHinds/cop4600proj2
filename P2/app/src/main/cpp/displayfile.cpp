#include "read_file.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    //this takes one command line argument
    //the filename of the file to be displayed on the screen. Use the read_file() function
    //displayfile /sdcard/example.txt
    char * filename = argv[1];
    char * output = read_file(filename);
    int i = 0;
    while(output[i] != '\0')
    {
        cout << output[i];
        i++;
    }
    free(output);
    return 0;
}
