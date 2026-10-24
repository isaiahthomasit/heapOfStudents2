all: main

main: main.o student.o address.o date.o
	g++ -g main.o student.o address.o date.o -o main

main.o: main.cpp student.h
	g++ -g -c main.cpp

student.o: student.cpp student.h address.h date.h
	g++ -g -c student.cpp

address.o: address.h address.cpp
	g++ -g -c address.cpp

date.o: date.h date.cpp
	g++ -g -c date.cpp

clean:
	rm main
	rm *.o

run: main
	./main
