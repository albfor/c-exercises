CC = gcc
LDFLAGS = -Wall
SRC = src
OBJ = build
BIN = bin

all: utility runner test
	
utility: ${SRC}/runner.c ${SRC}/employee.c
	${CC} -c ${SRC}/runner.c -o ${OBJ}/runner.o
	${CC} -c ${SRC}/employee.c -o ${OBJ}/employee.o

runner: ${OBJ}/runner.o ${OBJ}/employee.o
	strip -N main ${OBJ}/employee.o -o ${OBJ}/_employee.o
	${CC} -o bin/$@ ${OBJ}/runner.o ${OBJ}/_employee.o ${LDFLAGS}


test:
	${BIN}/runner

clean:
	rm ${OBJ}/* ${BIN}/*
