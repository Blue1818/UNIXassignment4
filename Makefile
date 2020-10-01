dog.exe: main.cc dog.cc dog.h
	g++ -std=c++11 -Wall -Wextra -pedantic -o dog.exe main.cc

clean:
	rm *.exe
