.PHONY : clean
OBJS = main.o mytbf.o

mytbf : main.o mytbf.o
	$(CC) -pthread $^ -o $@
main.o: main.c
	$(CC) -c $^ -o $@
mytbf.o: mytbf.c
	$(CC) -pthread -c $^ -o $@

clean:
	rm -rf $(OBJS) mytbf