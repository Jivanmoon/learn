server: main.o http_conn.o
	g++ -pthread $^ -o $@
%.o: %.c
	g++ -c $< -o $@