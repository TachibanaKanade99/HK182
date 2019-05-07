CC=gcc
CFLAGS = -Wall -Wextra -I.
RM = rm -f
LIBS = -lm

main: main.o Ex1.o
	$(CC) -o $@ $? $(LIBS)

main.o: main.c Ex1.h
	$(CC) -c $(CFLAGS) $?

Ex1.o: Ex1.c Ex1.h
	$(CC) -c $(CFLAGS) $(LIBS) $? 

clean:
	$(RM) *.o main