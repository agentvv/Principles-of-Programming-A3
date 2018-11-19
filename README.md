# Principles-of-Programming-A3
Third assignment for my principles of programming class

I only made the list.c file, the others were provided by the proffesor.

The goal of this assignment was to create 6 functions:
- createHBlist: Creates an HB list, initialized with random keys in sequence, a number of horizontal nodes equal to n, and with each node having a singly linked list with a number of nodes between 0 and m.

- flattenList: Takes an HB list and creates an SL list with the keys. The SL list must be organised from smallest to biggest key.

- freeSLlist: Frees the memory assigned to each node of a given SL list.

- freeHBlist: Frees the memory assigned to each node of a given HB list, including the nodes of the attached SL lists.

- printSLlist: Prints the keys of a given SL list, used mostly for testing.

- printHBlist: Prints the keys of a given HB list including the attached SL lists, used mostly for testing.


There was a challenge to try to write the code in  as little lines as possible, so my code in list.c is quite unreadable.
