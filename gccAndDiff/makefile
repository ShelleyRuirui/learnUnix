all: howdy hello showit

hello:hello.c
	gcc hello.c -o hello

howdy: howdy.o helper.o helper.h
	gcc howdy.o helper.o -o howdy

helper.o: helper.c helper.h
	gcc -c helper.c

howdy.o: howdy.c
	gcc -c howdy.c

clean:
	rm howdy hello showit *.o