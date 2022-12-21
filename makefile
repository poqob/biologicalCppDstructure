all: compile run
	

#ornek make file- bir onceki odevden
compile:
	g++ -I ./include/util -o ./lib/Timer.o -c ./src/util/Timer.cpp
	g++ -I ./include/util -o ./lib/Debug.o -c ./src/util/Debug.cpp
	g++ -I ./include/Bio -o ./lib/Cell.o -c ./src/Bio/Cell.cpp
	g++ -I ./include/BST -o ./lib/BST.o -c ./src/BST/BST.cpp
	g++ -I ./include/Bio -o ./lib/Organ.o -c ./src/Bio/Organ.cpp
	g++ -I ./include/Bio -o ./lib/Organism.o -c ./src/Bio/Organism.cpp
	g++ -I ./include/Bio -o ./lib/System.o -c ./src/Bio/System.cpp
	g++ -I ./include/LinkedSystemList -o ./lib/LinkedSystemList.o -c ./src/LinkedSystemList/LinkedSystemList.cpp
	g++ -I ./include/Bio -o ./lib/Tissue.o -c ./src/Bio/Tissue.cpp
	g++ -I ./include/radixsort -o ./lib/Queue2.o -c ./src/radixsort/Queue2.cpp
	g++ -I ./include/radixsort -o ./lib/Radix2.o -c ./src/radixsort/Radix2.cpp
	g++ -I ./include/Controll -o ./lib/Controll.o -c ./src/Controll/Controll.cpp
	g++ -I ./include/fileOperations -o ./lib/ReadFile.o -c ./src/fileOperations/ReadFile.cpp
	g++ -I ./include/UI -o ./lib/UI.o -c ./src/UI/UI.cpp
	g++ -c ./src/program.cpp -o ./lib/program.o
	
	g++ ./lib/Timer.o ./lib/Debug.o  ./lib/Cell.o ./lib/BST.o ./lib/Organ.o ./lib/Organism.o ./lib/System.o ./lib/LinkedSystemList.o ./lib/Tissue.o ./lib/Queue2.o  ./lib/Radix2.o ./lib/Controll.o ./lib/ReadFile.o ./lib/program.o ./lib/UI.o -o ./bin/program

run:
	./bin/program