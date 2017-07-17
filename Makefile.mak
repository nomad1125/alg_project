#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -c

all : algorithm_test

algorithm_test : main.cpp
	$(CC) $(CFLAGS) main.cpp -o algorithm_test



clean :
	rm -rf *o algorithm_test
