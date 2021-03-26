# -*- MakeFile _*_


test: test.o
	g++ test.o -o test

test.o: test.cpp ctimeit.h
	g++ test.cpp -c

run: test
	./test
	
clean:
	rm -f *.o test
