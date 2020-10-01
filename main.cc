/*	Dale Westberg z1910234
	CSCI 330
	Assignment #3
	9/18/20
*/
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
//#include <iomanip>
//#include <time.h> 
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <string.h>
//#include <cstdlib>
//#include <ctime>
//#include <vector>
//#include <queue>
//#include <fstream>
#include <sys/type.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;


int main(int argc, char *argv[])
{
	int fd; // file descriptor, or error code
	fd = open("path_to_a_file", O_RDWR | O_CREAT, 0755);
	if(fd == �1) 
	{
		perror("opening file"); // print human readable error
								// deal with the error, maybe exit if you can't recover
	}

	
	string fileNameone;
	cin >> s; // read from stdin
	
	
	
	cout << "This goes to stdout: got " << s << endl;
	cerr << "This goes to stderr: got " << s << endl;
	

	
	

	
	
	
	
	
	return 0;
}
