# LRU-implementation

This assignment was completed as part of my Operating Systems course. In this assignment, I aimed to maximize the performance of memory access in a set of predefined programs through implementing the LRU paging algorithm. The paging simulator (source code is in simulator.h and simulator.c) was provided for us. This simulator runs a random set of programs using a limited number of shared physical pages. Each process has a fixed number of virtual pages. The simulated program counter for each processes tells you which memory location the process wants access to, and which virtual page must be swapped in. 

I implemented the LRU algorithm in a function called pagein() which is contained in pager-lru.c. To run, use the make command and then enter "./test-lru." This will give you the performance of the implementation, which is the ratio of time spent doing useful work vs the time spent on waiting for the paging to occur (should be between 0.32 and 0.64 for LRU). 
