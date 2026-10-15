all: main

main: main.o address.o date.o
	g++ -g main.o address.o date.o -o main

main.o: main.cpp address.h date.h
	g++ -g -c main.cpp

address.o: address.h address.cpp
	g++ -g -c address.cpp

date.o: date.h date.cpp
	g++ -g -c date.cpp

clean:
	rm main
	rm *.o

run: main
	./main
