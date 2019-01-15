#include "read_file.h"
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <string>
using namespace std;

char *read_file(const char *filename)
{

	//code here
	//make POSIX call to read contents of 'filename' from disk
	//store it in a null-terminated char array (c-style string)
	//the array needs to be allocated dynamically (malloc)
	//a pointer to the array will be returned.
	//the caller will be expected to free the memory allocated for the array***
	//1. Open the file
	int fd = -1;
	fd = open(filename, O_RDONLY);
	if(fd == -1)	//if fd is negative 1 then the file did not open
	{
		cout << "Open failed";
		exit(EXIT_FAILURE);	//therefore exit in this case
	}
	//test to see what filename is

	//2. allocate the memory into the buffer string +1
	struct stat fileStat;
	fstat(fd, &fileStat);
	char *buff = (char*)malloc(fileStat.st_size + 1);
	if(buff==NULL) exit(1);

	//3. Populate the buffer string with the lines inside of the file
	ifstream myfile (filename);
	if(myfile.is_open())
	{
		myfile.get(buff, fileStat.st_size, '\0');
	}
	myfile.close();
	//4. Return the buffer string which contains the text inside the filename given
	return buff;
}

