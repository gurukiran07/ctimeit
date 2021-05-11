# Running the example code

```sh
$ make
-------SomeFunc---------
Average time taken : 903.081970µs (1000 runs)
Max time taken     : 1.523696ms
Min time taken     : 862.161987µs
-------anotherFunc with N arg---------
Average time taken : 41.000000ns (100 runs)
Max time taken     : 97.000000ns
Min time taken     : 36.000000ns
-------SomeFuncByRef with N arg---------
Average time taken : 903.028992µs (1000 runs)
Max time taken     : 1.477748ms
Min time taken     : 850.080994µs
---------FuncNoArgs-------------
Average time taken : 137.643005µs (1000 runs)
Max time taken     : 257.992004µs
Min time taken     : 132.184998µs

$ make clean
rm -f *.o test
```
