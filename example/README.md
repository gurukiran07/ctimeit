# Running the example code

```sh
make
g++ test.cpp -c
g++ test.o -o test
./test
-------SomeFunc---------
Average time taken : 953.950989µs (1000 runs)
Max time taken     : 1.895540ms
Min time taken     : 865.346985µs
-------anotherFunc with N arg---------
Average time taken : 41.000000ns (100 runs)
Max time taken     : 98.000000ns
Min time taken     : 37.000000ns
-------SomeFuncByRef with N arg---------
Average time taken : 883.598999µs (1000 runs)
Max time taken     : 1.296573ms
Min time taken     : 849.679016µs

make clean
rm -f *.o test
```
