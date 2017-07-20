#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -std=c++11

all : alg_prog

alg_prog : alg_test_prog.cpp
	$(CC) $(CFLAGS) alg_test_prog.cpp -o alg_prog

clean :
	rm -rf *o alg_prog
