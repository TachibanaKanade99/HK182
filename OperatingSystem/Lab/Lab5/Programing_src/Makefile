CC=gcc
CFLAGS = -Wall -Wextra -I.
RM = rm -f
LIBS = -pthread

MonteCarlos_PiCal_Multithread: 									MonteCarlos_PiCal_Multithread.o
		$(CC) -o $@ $? $(LIBS)

MonteCarlos_PiCal_Multithread.o: 								MonteCarlos_PiCal_Multithread.c 
		$(CC) -c $(CFLAGS) $(LIBS) $?
clean:
		$(RM) *.o MonteCarlos_PiCal_Multithread