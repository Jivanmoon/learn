.PHONY: clean

OBJ = main.o String.o 

main: $(OBJ)
	g++ $(OBJ) -o $@

%.o: %.c
	g++ -c $< -o $@

clean:
	rm -rf *.o main