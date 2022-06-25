.PHONY:clean

obj = main.o anytimer.o

main: $(obj)
%.o: %.c
	gcc -c $^ -o $@

clean:
	rm -rf *.o main