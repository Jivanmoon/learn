.PHONY: clean
CC = g++
OBJ = main.o StrBlob.o

main: $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf *.o main