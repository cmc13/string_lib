unit_tests.out: unit_tests.o unit_tests_str_new.o unit_tests_str_nnew.o string_lib.o
	gcc unit_tests.o unit_tests_str_new.o unit_tests_str_nnew.o string_lib.o -o unit_tests.out -lcunit
unit_tests.o: unit_tests.c ../string_lib.h
	gcc -c unit_tests.c
unit_tests_str_new.o: unit_tests_str_new.c ../string_lib.h
	gcc -c unit_tests_str_new.c
unit_tests_str_nnew.o: unit_tests_str_nnew.c ../string_lib.h
	gcc -c unit_tests_str_nnew.c
string_lib.o: ../string_lib.c ../string_lib.h
	gcc -c ../string_lib.c
clean:
	rm -rf *.o
	rm unit_tests.out
