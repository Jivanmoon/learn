.PHONY:clean

OBJ = main.o Quote.o

main: $(OBJ)
	g++ $^ -o $@

%.o: %.c
	g++ -c $<

clean:
	rm -rf *.o main