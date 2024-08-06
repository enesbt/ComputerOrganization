hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/File.o -c ./src/File.cpp
	g++ -I ./include/ -o ./lib/Registers.o -c ./src/Registers.cpp
	g++ -I ./include/ -o ./lib/Commands.o -c ./src/Commands.cpp

	g++ -I ./include/ -o ./bin/test  ./lib/File.o ./lib/Registers.o ./lib/Commands.o  ./src/test.cpp
	
calistir:
	./bin/test