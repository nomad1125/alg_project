#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -c

all : alg_prog

alg_prog : main.cpp
	$(CC) $(CFLAGS) main.cpp -o alg_prog $(OBJ)

clean :
	rm -rf *o alg_prog
