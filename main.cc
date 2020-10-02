/*	Dale Westberg z1910234
	CSCI 330
	Assignment #3
	10/2/20
*/
#include "dog.cc"

 

int main(int argc, char *argv[])
{
	char buffer[256];
	int fd; //for opening files.
	ssize_t nr; //number of bytes.
	ssize_t nw;

	//Check if there are no arguments from the commandline.
	if (argc <= 1)
	{
		perror("no argument");
		return 1;
	}

    //flags and parameters
    char optstring[] = "s:n:c:r:xb";
    //bool gotS = false;
    int chunkSize = 10; //size of buffer.
    //bool gotN = false;
    int numRead = -1; //if -1 then no limit.
    int numCount = 0;
    bool gotC = false;
    int numC = 0;
    bool gotR = false;
    int numR = 0;
    bool gotX = false;
    bool gotB = false;
    int opt;


    //run through argv with getopt
    while ((opt = getopt(argc, argv, optstring)) != (-1))
    {
        switch(opt)
        {
            case 's':
                //gotS = true;
                chunkSize = atoi(optarg);
                break;
            case 'n':
                //gotN = true;
                numRead = atoi(optarg);
cout << numRead;
                break;
            case 'c':
				if (gotR == true)
				{
					perror("both r and c");
					cout << "error";
					return 4;
				}
                gotC = true;            
                numC = atoi(optarg);
                break;
            case 'r':
				if (gotC == true)
				{
					perror("both r and c");
					cout << "error";
					return 4;
				}
                gotR = true;
                numR = atoi(optarg);
                break;
            case 'x':
				if (gotB == true)
				{
					perror("both x and b");
					cout << "error";
					return 4;
				}
                gotX = true;
                break;
            case 'b':
				if (gotX == true)
				{
					perror("both x and b");
					cout << "error";
					return 4;
				}
                gotB = true;
                break;
        }
    }





	
	cout << endl;
    //starts at the first nonparameter argument.
	for (int i = optind; i < argc; i++)
	{
		
		
		 if (*argv[i] == '-')
		{
			cout << "Input data: ";
			cin >> buffer;
			cout << endl << buffer << endl << endl;
		} else
		{
			
		
			//Open file.
			fd = open(argv[i], O_RDONLY | O_CREAT, 0644);
			//Check if it failed.
			if (fd == (-1))
			{
				perror("open");
				return 2;
			}
			
			//Say the file name and number.
			cout << "File number " << i << " " << argv[i] << ":" << endl << endl;
			numCount = 0;
			do //while the number of bytes is not 0 and numCount < numRead 
			{
				//check if the number of bytes remaining is less than the chunkSize
				//If so, set chunksize to the remaining amount of bytes to read.
			    if ((numRead - numCount) < chunkSize) chunkSize = numRead - numCount;

				//Read chunkSize bytes.
				nr = read(fd, buffer, chunkSize);
                numCount += nr;
				//Check if error.
				if (nr == (-1))
				{
					perror("read");
					return 3;
				}
				
				//Puts a null character at the end of the file.
				//Gets rid of extra lines when printed.
				buffer[nr] = 0;
				//For timing issues.
				cout.flush();
				
				//put flag stuff here
				//if -c call caeserCipher fuction
				if (gotC == true)
				{
					ceasarCipher(buffer, chunkSize, numC);
				}

				
				//Write the data to standard output.
				nw = write(1, buffer, nr);
			} while ((nr != 0) && ((numCount < numRead) || (numRead == -1))); 
            //while the number of bytes is not 0 and numCount < numRead

			cout << endl << endl;
			
			close(fd);
		}
	}
	return 0;
}
