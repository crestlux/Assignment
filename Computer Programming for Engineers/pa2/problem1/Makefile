# Write your makefile here
all: fraction
fraction: main.o fraction.o
	g++ -o fraction main.o fraction.o
main.o: main.cc fraction.h
	g++ -c main.cc
fraction.o: fraction.cc fraction.h
	g++ -c fraction.cc
clean:
	rm -rf *.o fraction