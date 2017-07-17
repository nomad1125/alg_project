#	Jarrett Tang (903482852)
#	Makefile
#	variables
CC = g++
CFLAGS = -c

all : alg_prog

audisktool_jkt0011 : main.cpp
	$(CC) $(CFLAGS) -o alg_prog $(OBJ)

clean :
	rm -rf *o alg_prog
