# -*- MakeFile _*_

run: test
	./test

test: test.o
	g++ test.o -o test

test.o: test.cpp ctimeit.h
	g++ test.cpp -c

clean:
	rm -f *.o test
