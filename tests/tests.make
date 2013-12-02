CC = gcc
OPTIONS = -Wall
OBJS = unit_tests.o string_lib.o unit_tests_str_new.o unit_tests_str_nnew.o

unit_tests.out: ${OBJS}
	${CC} ${OPTIONS} -o unit_tests.out ${OBJS} -lcunit

%.o: %.c
	${CC} ${OPTIONS} -c $*.c

string_lib.o: ../string_lib.c ../string_lib.h
	${CC} ${OPTIONS} -c ../string_lib.c

clean:
	rm -rf *.o
	rm unit_tests.out
