DIR = `basename $(PWD)`

CXX			= g++
CXXFLAGS 	= -std=c++11 -Wall -Wextra -g -pedantic
LFLAGS 		= 
APP	 		= main

DEP_FLAGS	= -MMD -MP
CXXFLAGS	+= $(DEP_FLAGS)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(APP)

$(APP): $(OBJ)
		$(CXX) -o $@ $(LFLAGS) $^

%.o: %.cpp
		$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(APP)
		./$(APP)

clean:
		rm -f $(APP) $(OBJ) $(DEP) ./*~

val: $(APP)
		valgrind --leak-check=full ./$<

.PHONY: all run clean val

-include $(DEP)