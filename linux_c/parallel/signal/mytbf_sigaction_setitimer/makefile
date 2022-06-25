.PHONY : clean
OBJS = main.o mytbf.o

mytbf : $(OBJS)
%.o : %.c
	$(CC) -c $^ -o $@

clean:
	rm -rf $(OBJS) mytbf