all:
	gcc -o test test.c src/*.c -g -fsanitize=address

rel:
	gcc -o test test.c src/*.c -O3
