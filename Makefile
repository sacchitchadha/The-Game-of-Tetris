CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = main.o Cell.o Block.o Board.o Coords.o Game.o iblock.o Interpretter.o Level.o Level0.o Level1.o Level2.o Level3.o OBlock.o SBlock.o Score.o TBlock.o TextView.o ZBlock.o JBlock.o LBlock.o window.o SpecialBlock.o Level4.o View.o GraphicView.o CBlock.o NBlock.o Level5.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = quadris
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
