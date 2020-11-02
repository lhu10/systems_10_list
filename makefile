all: main.o tv_show.o
	gcc -o tv_show main.o tv_show.o

main.o: main.c tv_show.c
	gcc -c main.c

tv_show.o: tv_show.c tv_show.h
	gcc -c tv_show.c

run:
	./tv_show
