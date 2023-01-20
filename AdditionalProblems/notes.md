**Shortest Subsequence**
**Counting Bits**
**Swap Game**

Bidirectional bfs. Rather than iterating through all four directions for all 
spots in the grid to compute swaps, precompute all possible swaps. Turns out
that there are only 12 such swaps. So for each grid position, can very quickly
find all next possible positions. Bfs runs from the starting grid and from the
target grid simultaneously to further speed things up. 

**Prüfer Code**
**Acyclic Graph Edges**
**Strongly Connected Edges**
**Even Outdegree Edges**
**Multiplication Table**
**Advertisement**
**Special Substrings**
**Permutation Inversions**
**Maximum Xor Subarray**
**Movie Festival Queries**
**Chess Tournament**
**Tree Traversals**
**Network Renovation**
**Graph Girth**
**Intersection Points**
**Inverse Inversions**
**Monotone Subsequences**
**String Reorder**
**Stack Weights**
**Pyramid Array**
**Increasing Subsequence II**

While processing array, for each number n need to know the sum subs[i] for i < n
where subs[i] is the number of subsequences ending with the number i. From this 
want to increment the total count and subs[n] by sum(subs[i]: i < n) + 1, the +1
being for the subsequence of just [n]. The easiest way to do this is with a binary
indexed tree. However, since n can be up to 10^9, cannot use n to index the tree.
Instead, preprocess the input, storing all numbers in a map (this also eliminates
duplicates). Then iterate through the map, assigning the first number an index of 2,
the second number an index of 3, and so on. This compresses the values of n to a range
that can be represented in an array. (Starting at 2 just makes things easier by 
eliminating edge cases). 

**String Removals**
**Bit Inversions**
**Xor Pyramid**
**Writing Numbers**
**String Transform**
**Letter Pair Move Game**
**Maximum Building I**
**Sorting Methods**
**Cyclic Array**
**List of Sums**
**Increasing Array II**
**Food Division**
**Bit Problem**
**Swap Round Sorting**
**Binary Subsequences**
**Tree Isomorphism I**
**Counting Sequences**
**Critical Cities**
**School Excursion**
**Coin Grid**
**Robot Path**
**Programmers and Artists**
**Course Schedule II**
**Removing Digits II**
**Coin Arrangement**
**Counting Bishops**
**Grid Puzzle I**
**Grid Puzzle II**
**Empty String**
**Grid Paths**
**Bit Substrings**
**Reversal Sorting**
**Counting Reorders**
**Book Shop II**
**Network Breakdown**
**Visiting Cities**
**Missing Coin Sum Queries**
**Number Grid**
**Maximum Building II**
**Filling Trominos**
**Stick Divisions**

Build up the original stick backwards from the fragments. Greedily combine the two 
smallest sticks every time. This makes the stick divisions as balanced, and therefore
cheap, as possible

**Coding Company**
**Flight Route Requests**
**Two Stacks Sorting**
**Tree Isomorphism II**
**Forbidden Cities**
**Area of Rectangles**
**Grid Completion**
**Creating Offices**
**Permutations II**
**Functional Graph Distribution**
**New Flight Routes**
**Grid Path Construction**