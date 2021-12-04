all				:	BUILD

BUILD			:	dive.o
					g++ -o dive.exe dive.o

dive.o	:	dive.cpp
					g++  -I ./ -c dive.cpp

clean			:	dive.exe
					del *.o 
					del dive.exe