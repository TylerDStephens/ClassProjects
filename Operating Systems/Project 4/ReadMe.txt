Coded in C++
By Tyler D Stephens
I also used https://solver.assistedcoding.eu/page_replacement to check my results.
I ran and tested my code on the Tx State linux server and on CodeBlocks and it ran perfectly fine on each.
g++ Project4-tds153.cpp -o project4 -std=c++11 (You need to include standatd C++ 11 or else it will not run on
the linux server as it will give you an error message).
Also just like to note that the random string generator will often generate the same string for some odd reason. I think its the lack of variables being its only 1-5.

The first algorithm to run will be the LRU algorithm. The tester will simply input the number of frames
that are to be used. Then the alogrith will run through and everytime there is a miss it will look back and
see what frames have been used and replace the frame depending on the value given.

The second algorithm will be the Optimal algorithm. This algorithm will run through the pages and will have 
a frame holder deque. Whenever a miss occurs it will look into the future and figure out which has the most time
until used again. The deque will be sorted based on this knowledge then the deque will push out the value that has 
the most time until being used again. If there is a tie it will kick out the one that happens to be in that last position 
in the queue. Then the new page will be pushed into that front slot of the queue.