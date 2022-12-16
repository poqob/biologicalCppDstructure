all: compile run
	

#ornek make file- bir onceki odevden
compile:
	g++ -I ./include/Bio -o ./lib/Cell.o -c ./src/Bio/Cell.cpp
	g++ -I ./include/Bio -o ./lib/Organ.o -c ./src/Bio/Organ.cpp
	g++ -I ./include/Bio -o ./lib/Organism.o -c ./src/Bio/Organism.cpp
	g++ -I ./include/Bio -o ./lib/System.o -c ./src/Bio/System.cpp
	g++ -I ./include/Bio -o ./lib/Tissue.o -c ./src/Bio/Tissue.cpp
	g++ -I ./include/radixsort -o ./lib/Queue.o -c ./src/radixsort/Queue.cpp
	g++ -I ./include/radixsort -o ./lib/Radix.o -c ./src/radixsort/Radix.cpp
	g++ -c ./src/program.cpp -o ./lib/program.o
	g++ ./lib/Cell.o ./lib/Organ.o ./lib/Organism.o ./lib/System.o ./lib/Tissue.o ./lib/Queue.o ./lib/Radix.o ./lib/program.o  -o ./bin/program

run:
	./bin/program