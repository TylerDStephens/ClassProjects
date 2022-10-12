4328.751 Tyler Stephens Project 3 README
Concurrent execution of two threads Thread A and Thread B. Please use Zeus or Eros TxState linux servers to run the program.

For Project3_a.c, gcc Project3_a.c -o project3_a -lpthread is what I used to compile and run it. 
Part a is without mutex so it prints out N:AAAAAAA N:BBBBBBB in a almost random fashion. The B thread also gets tripped up by the 
A thread, so the B thread will start getting "behind" the B thread.

For Project3_b.c, gcc Project3_b.c -o project3_b -lpthread is what I used to compile and run it. 
Part B is the one using mutual exclusion so it runs through the program and prints out 5 rows of A's
then the 5 rows of B's till it finishes through the loop.