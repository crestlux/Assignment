# Write your makefile here
# Build an executable binary named "arrayModify"
all: arrayModify

arrayModify: main.o arrayModify.o
	g++ -o arrayModify main.o arrayModify.o

main.o: main.cc arrayModify.h
	g++ -c main.cc

arrayModify.o: arrayModify.cc arrayModify.h
	g++ -c arrayModify.cc

clean:
	rm -rf *.o arrayModify
