#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -c
OBJ = generate_arrays.o

all : alg_prog

alg_prog : alg_test_prog.cpp $(OBJ)
	$(CC) alg_test_prog.cpp -o alg_prog

generate_arrays.o : generate_arrays.cpp generate_arrays.h
	$(CC) $(CFLAGS) generate_arrays.cpp

clean :
	rm -rf *o alg_prog
