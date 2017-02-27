CC= gcc
CFLAGS= -std=c99 -Wall -g
mainexec: esami.c fuffa.c test.c
	$(CC) $(CFLAGS) -o Alga esami.c fuffa.c test.c
