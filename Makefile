CC=gcc
CFLAGS=-g -Wall --std=c99
OBJECTS=main.o my_string.o vector.o

string_driver:$(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o:my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
vector.o:vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c -o vector.o
unit_test:my_string.o unit_test.o test_def.o vector.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o vector.o
unit_test.o:unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o:test_def.c unit_test.h
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
clean:
	rm string_driver $(OBJECTS) unit_test unit_test.o test_def.o
