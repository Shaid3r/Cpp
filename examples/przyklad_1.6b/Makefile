CXX = g++
CXXFLAGS = -Wall -g
EXEC = run


$(EXEC) : $(patsubst %.cpp, %.o, $(wildcard *.cpp))
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp %.dep
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.dep : %.cpp
	g++ -MM -MT ${@:.dep=.o} $< -MF $@

include $(wildcard *.dep)

clean :
	rm -rf *.o *.dep $(EXEC)

test :
	valgrind ./$(EXEC)

.PHONY: clean test 
.SUFFIXES:
.SECONDARY:

