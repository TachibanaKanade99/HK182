CC=gcc
CFLAGS = -Wall -Wextra -I.
RM = rm -f

main: paging.o
	$(CC) -o $@ $?

paging: paging.c 
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) *.o main 