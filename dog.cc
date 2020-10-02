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
void rotate(char buffer[], int numSize, int shift)
{
    for (int i = 0; i < numSize; i++)
    {
        for (int j = 0; j < shift; j++) buffer[i]++;
    }
}

// • The ability to specify a command line option (­x) to output the data in the file as hexadecimal.
int toHex(char buffer[], int numSize)
{
    char newbuffer[BUFFER_SIZE];
    char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int val = 0; //ASCII value of the character.
    int first = 0;
    int second = 0;
    
    for(int i = 0; i < numSize; i++)
    {
        val = buffer[i];
        //Find the index for first hex bit.
        first = val / 16;
        //The remainder is the index for the second hex bit.
        second = val - first;
        //use the hex char array with first and second.
        //to input the hex characters into the newbuffer.
        newbuffer[i*2] = hex[first];
        newbuffer[(i*2) + 1] = hex[second]
    }

    //load newbuffer into buffer with a for loop.
    for (size_t int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = newbuffer[i];
    }


    return numSize * 2;
}

// • The ability to specify a command line option (­b) to output in binary notation, most significant bit
// first.


