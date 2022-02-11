all: skku_sh
skku_sh: main.o Directory.o File.o Entry.o
	g++ -o skku_sh main.o Directory.o File.o Entry.o
main.o: main.cc Entry.h Directory.h File.h
	g++ -c main.cc
Entry.o: Entry.h
	g++ -c Entry.cc
Directory.o: Directory.h
	g++ -c Directory.cc
File.o: File.h
	g++ -c File.cc
clean:
	rm -rf *.o skku_sh
