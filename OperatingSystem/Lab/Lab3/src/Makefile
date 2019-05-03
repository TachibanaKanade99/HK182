CC=gcc
CFLAGS = -Wall -Wextra -I.
RM = rm -f

main: main.o getPID.o create_pro.o Multipro.o pro_info.o Ex3.o
	$(CC) -o $@ $? 

main.o: main.c getPID.h create_pro.h Multipro.h pro_info.h Ex3.h
	$(CC) -c $(CFLAGS) $? 

getPID.o: getPID.c getPID.h
	$(CC) -c $(CFLAGS) $? 

create_pro.o: create_pro.c create_pro.h
	$(CC) -c $(CFLAGS) $?

Multipro.o: Multipro.c Multipro.h
	$(CC) -c $(CFLAGS) $?

pro_info.o: pro_info.c pro_info.h
	$(CC) -c $(CFLAGS) $?

Ex3.o: Ex3.c Ex3.h
	$(CC) -c $?
clean:
	$(RM) *.o main