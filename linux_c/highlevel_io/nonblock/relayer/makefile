


relayer: relayer.o main.o
	gcc -pthread $^ -o $@

%.o: %.c
	gcc -pthread -c $<

clean:
	rm -rf *.o relayer