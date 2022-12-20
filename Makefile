CXX := g++
CXXFLAGS := -g -Wall --std=c++11
GTESTINCL := -I /usr/include/gtest/  
GTESTLIBS := -lgtest -lgtest_main  -lpthread
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec.o : llrec.cpp llrec.h	
	$(CXX) $(CXXFLAGS) -c $< -o $@
llrec-test.o : llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
llrec-test : llrec-test.cpp llrec.o
	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	rm -f *.o llrec-test *~

.PHONY: clean 
