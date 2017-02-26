CC= gcc
CFLAGS= -std=c99 -Wall -g
mainexec: test.c alg.c
	$(CC) $(CFLAGS) -o Test test.c alg.c
