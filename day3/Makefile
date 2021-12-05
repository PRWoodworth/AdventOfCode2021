all				:	BUILD

BUILD			:	binDiag.o
					g++ -o binDiag.exe binDiag.o

binDiag.o	:	binDiag.cpp
					g++  -I ./ -c binDiag.cpp

clean			:	binDiag.exe
					del *.o 
					del binDiag.exe