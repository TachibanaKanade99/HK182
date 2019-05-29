CC=gcc
CFLAGS = -Wall -Wextra -I.
RM = rm -f
LIBS = -pthread

main: main.o HelloWorld_Thread.o
	$(CC) -o $@ $? $(LIBS)

main.o: main.c HelloWorld_Thread.h
	$(CC) -c $(CFLAGS) $(LIBS) $?

HelloWorld_Thread.o: HelloWorld_Thread.c HelloWorld_Thread.h
	$(CC) -c $(CFLAGS) $(LIBS) $? 

clean:
	$(RM) *.o main