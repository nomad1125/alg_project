#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -std=c++11

all : algorithm_test

algorithm_test : main.cpp
	$(CC) -o algorithm_test



clean :
	rm -rf *o algorithm_test
