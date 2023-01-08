CXX=g++

cell.o: cell.cpp cell.h
	${CXX} -c cell.cpp -o $@
	${CXX} -S cell.cpp -o cell.asm

minesweeper: cell.o board.o game.o runMinesweeper.o
	${CXX} $^ -o $@

clean:
	rm -f minesweeper *.o

