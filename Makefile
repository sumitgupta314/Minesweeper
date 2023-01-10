CXX=g++

cell.o: Cell.cpp Cell.h
	${CXX} -c $^ -o $@
	${CXX} -S Cell.cpp -o cell.asm

minesweeper: Cell.o Board.o Game.o runMinesweeper.o
	${CXX} $^ -o $@
#	${CXX} -S Cell.cpp Board.cpp Game.cpp runMinesweeper.cpp

clean:
	rm -f minesweeper *.o *.asm *.s

