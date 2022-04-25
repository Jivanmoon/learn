CFLAGS+=-D_FILE_OFFSET_BITS=64

mygetline_test: mygetline_test.o mygetline.o
	gcc -Wall -g mygetline_test.o mygetline.o -o mygetline_test
mygetline_test.o: mygetline_test.c
	gcc -Wall -g -c mygetline_test.c -o mygetline_test.o
mygetline.o: mygetline.c
	gcc -Wall -g -c mygetline.c -o mygetline.o