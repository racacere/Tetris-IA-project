all: tetris

tetris: functions.o tetris.o
	g++ -Wall -o tetris functions.o tetris.o

tetris.o: tetris.cpp functions.h
	g++ -c tetris.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

clean:
	rm *.o
