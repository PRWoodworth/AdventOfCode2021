all				:	BUILD

BUILD			:	sonarsweep.o
					g++ -o sonarsweep.exe sonarsweep.o

sonarsweep.o	:	sonarsweep.cpp
					g++  -I ./ -c sonarsweep.cpp

clean			:	sonarsweep.exe
					del *.o 
					del sonarsweep.exe