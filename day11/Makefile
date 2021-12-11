all				:	BUILD

BUILD			:	octoFlash.o
					g++ -o octoFlash.exe octoFlash.o

octoFlash.o	:	octoFlash.cpp
					g++  -I ./ -c octoFlash.cpp

clean			:	octoFlash.exe
					del *.o 
					del octoFlash.exe