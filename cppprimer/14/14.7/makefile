.PHONY:clean
CC=g++
OBJS = main.o String.o

main: $(OBJS) 
%.o : %.c
	$(CC) -c $^ -o $@

clean:
	-rm -rf $(OBJS) main