/*	Dale Westberg z1910234
	CSCI 330
	Assignment #3
	10/2/20
*/
#include "dog.h"

// The ability to specify a command line option (­s x) to change the size of the buffer used for calls to
// read and write to be x bytes.


// • The ability to specify a command line option (­n x) to change the number of bytes read from each file
// to x. (Instead of reading the whole file as we would have without this option.)


// • The ability to specify a command line option (­c x) to have the program apply a Caesar cipher with a
// shift of x to alphabetical characters in the data read before writing its results.
void cipher(char buffer[], int numSize, int shift)
{
    //isalpha(char) returns 0 if char is a alphabetic letter.
    for (int i = 0; i < numSize; i++)
    {
        //check if buffer is a letter
        if (isalpha(buffer[i]) != 0)
        {
            for(int j = 0; j < shift; j++)
            {
                if (buffer[i] == 'z')
                {
                    buffer[i] = 'a';
                } else if (buffer[i] == 'Z')
                {
                    buffer[i] = 'A';
                } else
                {
                    buffer[i]++;
                }
            } 
        }
    }
}

// • The ability to specify a command line option (­r x) to have the program apply a rotation of x to each
// byte read from the file before sending the data to be output.


// • The ability to specify a command line option (­x) to output the data in the file as hexadecimal.


// • The ability to specify a command line option (­b) to output in binary notation, most significant bit
// first.


