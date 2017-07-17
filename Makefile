#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++

all : alg_prog

alg_prog : main.cpp
	$(CC) main.cpp -o alg_prog

clean :
	rm -rf *o alg_prog
