.PHONY : clean
OBJS = main.o mysem.o

mysem : main.o mysem.o
	$(CC) -pthread $^ -o $@
main.o: main.c
	$(CC) -c $^ -o $@
mysem.o: mysem.c
	$(CC) -pthread -c $^ -o $@

clean:
	rm -rf $(OBJS) mysem