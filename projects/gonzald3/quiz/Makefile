CFLAGS = -Wall -fpic --coverage -lm

testme:
	gcc -o testme -g testme.c $(CFLAGS)


all: testme

clean:
	rm -f testme *.gcov *.gcda *.gcno *.o