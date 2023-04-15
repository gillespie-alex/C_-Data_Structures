# -*- MakeFile -*-

CC=gcc

all: hashmap_prog string_prog



hashmap_prog: hashtable.o hashtable_testing.o
	$(CC) hashtable.o hashtable_testing.o -o hashmap_prog

hashtable.o: src/hashtable.c include/hashtable.h
	$(CC) -c src/hashtable.c -I include/

hashtable_testing.o: tests/hashtable_testing.c include/hashtable.h
	$(CC) -c tests/hashtable_testing.c -I include/


string_prog: Str.o string_testing.o
	$(CC) Str.o string_testing.o -o string_prog

Str.o: src/Str.c include/Str.h
	$(CC) -c src/Str.c -I include/

string_testing.o: tests/string_testing.c include/Str.h
	$(CC) -c tests/string_testing.c -I include/


clean:
	rm *.o hashmap_prog string_prog

