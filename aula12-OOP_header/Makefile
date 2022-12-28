my_program: sensor.o
	g++ -o my_program sensor.o
	./my_program
	rm ./my_program ./sensor.o
sensor.o: sensor.cpp sensor.h
	g++ -c -Wall sensor.cpp -o sensor.o


