# Write your makefile here
# Build an executable binary named "wordProcess"
all: wordProcess

wordProcess: main.o wordProcess.o
	g++ -o wordProcess main.o wordProcess.o

main.o: main.cc wordProcess.h
	g++ -c main.cc

wordProcess.o: wordProcess.cc wordProcess.h
	g++ -c wordProcess.cc

clean:
	rm -rf *.o wordProcess