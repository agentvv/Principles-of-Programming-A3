main: main.o list.o assignment3.h
	gcc -o main main.o list.o assignment3.h -Wall

main.o: main.c assignment3.h
	gcc -c main.c assignment3.h -Wall

list.o: list.c assignment3.h
	gcc -c list.c assignment3.h -Wall

full: listBefore1.c assignment3.h main.c
	clang-format listBefore1.c > list.c
	cloc list.c
	make

clean:
	rm list.o main.o main assignment3.h.gch
