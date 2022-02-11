# Write your makefile here
# Build an executable binary named "guessGame"
all: guessGame

guessGame: main.o guess.o
	g++ -o guessGame main.o guess.o

main.o: main.cc guess.h
	g++ -c main.cc

guess.o: guess.cc guess.h
	g++ -c guess.cc

clean: 
	rm -rf *.o guessGame