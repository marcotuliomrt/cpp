
FILE = sensor 
LDFLAGS =  -g -Wall 
CC = g++

#build: $(FILE)

$(FILE): sensor.o
	$(CC) $(LDFLAGS)   $^ -o $@ 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(FILE)
	./$(FILE)

.PHONY: clean
clean:
	rm -f $(FILE) *.a *.o *~


