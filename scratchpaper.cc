#include <iostream>
//#include <sys/type.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //for getopt function
using namespace std;


int main(int argc, char *argv[])
{
    int opt;
    bool cflagused=false;
    int gotc = 0; //number of times optional parameter used
    char optstring[] = "c";

    //Each step of this loop handles one optstring[] = "c";
    while ((opt = getopt(argc, argv, optstring)) != (-1)) // end when -1 is returned.
    {
        switch(opt)
        {
            //1 case for each optional parameter.
            case 'c':
                //run any option-specific code here.

                //prints argument after optional parameter.
                cout << argv[optind] << endl;

                //used to dectect if option was chosen.
                cflagused = true;
                //incrments counter
                gotc++;
                break;
        }
    }
    //when the code reaches here, the -c option will
    // no longer be in the argc, argv list.
    for (int i = 1; i < argc; i++) cout << argv[i] << endl;
    cout << endl;

    return 0;
}

/*
Samples"
input:
./a.out he voej -c fe "f ei fw" -c fe

output:
flag
flag
./a.out
-c
-c
he
voej
fe
f ei fw
fe

*/






