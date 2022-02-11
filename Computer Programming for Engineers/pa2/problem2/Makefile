# Write your makefile here
all: calculator
calculator: main.o calculator.o
	g++ -o calculator main.o calculator.o
main.o: main.cc calculator.h
	g++ -c main.cc
calculator.o: calculator.cc calculator.h
	g++ -c calculator.cc
clean:
	rm -rf *.o calculator