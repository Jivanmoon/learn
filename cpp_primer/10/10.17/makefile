.PHONY:clean
CC=g++
OBJS = main.o Sales_data.o

main: $(OBJS) 
%.o : %.c
	$(CC) -c $^ -o $@

clean:
	-rm -rf $(OBJS) main