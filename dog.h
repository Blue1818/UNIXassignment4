/*	Dale Westberg z1910234
	CSCI 330
	Assignment #3
	10/2/20
*/
#ifndef H_DOG
#define H_DOG

#include <iostream>
//#include <sys/type.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;


//encripts the buffer using the Caesar cipher.
void cipher(char [], int, int);

//incrment each byte.
void rotate(char [], int, int);

//change buffer hex and returns chunkSize * 2
int toHex(char [], int);


#endif