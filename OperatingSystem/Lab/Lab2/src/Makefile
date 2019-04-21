all: main.o readline.o findsubstr.o 
	gcc -o mygrep main.o readline.o findsubstr.o

main.o: main.c readline.c findsubstr.c
		gcc -c main.c readline.c findsubstr.c -I.

readline.o: readline.c readline.h
				gcc -c readline.c -I.

findsubstr.o: findsubstr.c findsubstr.h
				gcc -c findsubstr.c -I.

clean:
		rm -f *.o mygrep