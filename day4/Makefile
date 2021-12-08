all				:	BUILD

BUILD			:	bingo.o
					g++ -o bingo.exe bingo.o

bingo.o	:	bingo.cpp
					g++  -I ./ -c bingo.cpp

clean			:	bingo.exe
					del *.o 
					del bingo.exe