all: compile run
	

#ornek make file- bir onceki odevden
compile:
	g++ -I ./include/ -o ./lib/printfile.o -c ./src/printfile.cpp 
	g++ .lib/printfile.o -o ./bin/program

run:
	./bin/program