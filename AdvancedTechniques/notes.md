**Meet in the Middle**

Split the input numbers into two parts. For the first half, iterate through all subsets and 
save the number of occurrences for each subset within a map. Then for the second half, iterate
through all subsets and count the number of times the complement (x - sum) occurs in the first
half. By iterating over subsets in halves, runtime is reduced from O(2^n) to O(2^n/2). Note that
map queries are done through find() rather than [ ], since [ ] modifies this list and causes the
time limit to be exceeded.

**Hamming Distance**

Convert each bit string into an int. Since bit operations are so fact, can just do brute force 
O(n^2) solution of checking the distance between every pair of strings.

**Beautiful Subgrids**

General algorithm is to iterate over all pairs of rows and for each pair count how many squares
are black in both. Then to the total add count * (count - 1) / 2 because this is the number of ways
to choose pairs of columns. To optimize this, each row is represented as a bitset, so the number 
of common black squares in two rows is the count of 1's in their AND. For some reason, this code
only passes the autograder when #pragma GCC target("popcnt") is included.



**Reachable Nodes**
**Reachability Queries**
**Cut and Paste**
**Substring Reversals**
**Reversals and Sums**
**Necessary Roads**
**Necessary Cities**
**Eulerian Subgraphs**
**Monster Game I**
**Monster Game II**
**Subarray Squares**
**Houses and Schools**
**Knuth Division**
**Apples and Bananas**
**One Bit Positions**
**Signal Processing**
**New Roads Queries**
**Dynamic Connectivity**
**Parcel Delivery**
**Task Assignment**
**Distinct Routes II**