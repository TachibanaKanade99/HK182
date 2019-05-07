CC=gcc
CFLAGS = -Wall -Wextra -I.
RM = rm -f

main: main.o printfunc.o mem_allocate.o
	$(CC) -o $@ $? 

main.o: main.c printfunc.h mem_allocate.h
	$(CC) -c $(CFLAGS) $? 

printfunc.o: printfunc.c printfunc.h
	$(CC) -c $(CFLAGS) $?

mem_allocate.o: mem_allocate.c mem_allocate.h
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) *.o main