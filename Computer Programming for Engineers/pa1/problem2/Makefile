# Write your makefile here
# Build an executable binary named "arabians"
all: arabians

arabians: main.o display.o arabians.o
	g++ -o arabians main.o display.o arabians.o

main.o: main.cc display.h arabians.h
	g++ -c main.cc

display.o: display.cc display.h
	g++ -c display.cc

arabians.o: arabians.cc arabians.h
	g++ -c arabians.cc

clean:
	rm -rf *.o arabians