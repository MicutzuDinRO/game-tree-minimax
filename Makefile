CC = gcc
CFLAGS = -Wall -std=c99

build: main.c minimaxtree.h normaltree.h queue.h minimax.h gametrees.h tictactoe.h
	$(CC) $(CFLAGS) main.c minmaxtree.h normaltree.h queue.h minimax.h gametrees.h tictactoe.h -o minimax

clean:
	rm -f minimax
	rm -f *.gch