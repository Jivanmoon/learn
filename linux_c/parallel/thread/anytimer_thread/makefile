.PHONY:clean
obj = main.o anytimer.o

main: $(obj)
	gcc -pthread $(obj) -o $@
%.o: %.c
	gcc -pthread -c $^ -o $@

clean:
	rm -rf *.o main