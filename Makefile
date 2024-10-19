CC=clang
CFLAGS=-Wall -g
LIBS=-lraylib

run: game
	./fnaf_fangame

game: src/*.c
	$(CC) $(CFLAGS) $(LIBS) src/*.c -o fnaf_fangame
