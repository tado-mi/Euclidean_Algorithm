# showing off:

**author:** Lusine Keshishyan / tado-mi

**date:**   12 Apr 2018

**use:**    free. credit when due is encouraged and appreciated

# general:

included is a package of C source code files to calculate the [GCD](https://en.wikipedia.org/wiki/Greatest_common_divisor) and the associated [Bézout's identity](https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity) of any 2 integers using the [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm).

# included files:

## jammed.c:

all the created data structures / code jammed all together in one file, since at a time I had vague idea of how to use header files and the include operation
included since there is a non-zero probability it would prove less confusing and thus more helpful to people just getting to know c and gcc

## main.c:

the main file that test / demonstrates the provided data structures and functions

## tuple.c:

### tuple

a simple data structure consisting of 5 ints such that a = bq + rc

**print_tuple(tuple me):** is a messy, yet trivial method that ensures the tuple is printed out in a human-friendly, pretty form
**is_correct(tuple t):** is the non-trivial function that simply checks whether the numbers stored inside the tuple satisfy their 'characteristic' eqution of a = bq + rc

### stack
a simple implementation of the [stack](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29) data structure with its data hard-coded as a tuple

## gcd.c
recursive implementation of Euclidean algorithm

**gcd_st(a, b, S):** while *a* is not a multiple of *b*, a tuple representing *a = bq + r* is pushed on top of stack S and a recursive call is made for b and r, otherwise S is returned
- maintainence of the stack representing the steps of the execution of Euclidean algorithm will be useful for implementation of function outputting the Bézout's identity.

**gcd(a, b):** initialises and empty stack S and calls the earlier described method of **gcd_st(a, b, S)** and retrives the neseccary value from the top of S.

## bezout.c
Bézout's identity for numbers *a* and *b* is *am + bn = gcd(a, b)*, where m and n are coprime integers. It is possible to find m and n working backwards from the Euclidean algorithm.

**rev_euclid(a, b):** works backwards from the stack of equations produced for Euclidean algorithm and substitutes values.

**bezout(a, b):** takes care of logistics and returns the top equation on the stack produced by the reverse Euclidean algorithm implemented earlier.

## makefile:

For more information on the magic, see [here](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html).

## compiling:

to work with the jammed.c file hit on terminal:
    
	gcc jammed.c -o j.out
	./j.out
	
for the rest of them:

	make
	make run
	make clean

# other

shall such desire be felt, feel free to report bugs/suggestions/questions to tadouchiha@gmail.com

