CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = main.o view.o controller.o game.o player.o textdisplay.o map.o building.o academic.o coop.o dctl.o goose.o gtt.o gym.o nh.o osap.o ownable.o residence.o slc.o tuition.o unownable.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
