# Euclidean algorithm

Included is a package of C source code files to calculate the [greates common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) and the associated [Bézout's identity](https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity) of any 2 integers using the [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm). It was written as an excercise in coding in C, and in particular how to use header files well (: better than the day before).

# Files:

## src/tuple.c:

a simple data structure consisting of 5 integers such that `a = bq + rc`. It includes some simple functions:

* **print_tuple(tuple me):** is a messy, yet trivial function that ensures the tuple is printed out in a human-readable form

* **is_correct(tuple t):** is the non-trivial function that simply checks whether the numbers stored inside the tuple satisfy their 'characteristic' equation of `a = bq + rc`

## src/gcd.c

Contains the recursive implementation of Euclidean algorithm.

* **gcd_st(a, b):** while `a` is not a multiple of `b`, a tuple representing `a = bq + r` is pushed on top of stack `S`, and a recursive call is made for `b` and `r`, otherwise returns `S` and is terminated. Note that maintaining the stack `S`, which is representing the steps of the execution of Euclidean algorithm, will be useful for implementation of function outputting the Bézout's identity.

**gcd(a, b):** initializes an empty stack `S` and calls the earlier described method of `gcd_st(a, b, S)` and retrives the neseccary value from the top of `S`.

## src/bezout.c

Contains the implementation of the function finding the identity (`identity(a, b)`), and relevant functions.

Bézout's identity for numbers `a` and `b` is `am + bn = gcd(a, b)`, where `m` and `n` are coprime integers. It is possible to find `m` and `n` working backwards from the Euclidean algorithm.

# Run

There is an included `makefile` for your (and our) convenience.

  make
  make run
  make clean

note that the code as is will not run, as the stack file is not included.

# Future plans

- [ ] add user interaction
