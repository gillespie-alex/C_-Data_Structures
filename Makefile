# -*- MakeFile -*-

CC=gcc

all: hashmap_prog string_prog set_prog

# Make for Set stuff
set_prog: set.o set_testing.o sort_array.o
	$(CC) set.o set_testing.o sort_array.o -o set_prog

set.o: src/set.c include/set.h helpers/include/sort_array.h
	$(CC) -c src/set.c -I include/ -I helpers/include/

set_testing.o: tests/set_testing.c include/set.h
	$(CC) -c tests/set_testing.c -I include/

sort_array.o: helpers/src/sort_array.c helpers/include/sort_array.h
	$(CC) -c helpers/src/sort_array.c -I helpers/include/


# Make for hashtable stuff
hashmap_prog: hashtable.o hashtable_testing.o
	$(CC) hashtable.o hashtable_testing.o -o hashmap_prog

hashtable.o: src/hashtable.c include/hashtable.h
	$(CC) -c src/hashtable.c -I include/

hashtable_testing.o: tests/hashtable_testing.c include/hashtable.h
	$(CC) -c tests/hashtable_testing.c -I include/


# Make for Dynamic String stuff
string_prog: Str.o string_testing.o
	$(CC) Str.o string_testing.o -o string_prog

Str.o: src/Str.c include/Str.h
	$(CC) -c src/Str.c -I include/

string_testing.o: tests/string_testing.c include/Str.h
	$(CC) -c tests/string_testing.c -I include/


clean:
	rm *.o hashmap_prog string_prog set_prog

