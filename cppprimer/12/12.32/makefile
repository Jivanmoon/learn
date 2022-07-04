.PHONY: clean
CC = g++
OBJ = main.o TextQuery.o StrBlob.o

main: $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf *.o main