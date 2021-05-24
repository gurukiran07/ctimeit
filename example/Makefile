# -*- MakeFile _*_

CXX = g++
CXXFLAGS = -std=c++11

run: test
	@./test

test: test.o
	$(CXX) $(CXXFLAGS) test.o -o test

test.o: test.cpp ctimeit.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
	
clean:
	rm -f *.o test
