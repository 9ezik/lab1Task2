all: main test

main: task2.c
	gcc task2.c -o task2 -lm 
test: task2
	./task2
