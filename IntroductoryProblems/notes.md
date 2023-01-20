**Weird Algorithm**

Straightforward. Just use long long instead of int to avoid overflow.

**Missing Number**

Compare sum of numbers to closed form for sum. Difference is what's missing.

**Repetitions**

Count each streak and set max accordingly.

**Increasing Array**

If a number is greater than the last, we set the last to be that number. Otherwise, increase
the current number to be the same as the last and add that to the total number of moves.

**Permutations**

Alternate printing from middle of the string and printing from the beginning.

**Number Spiral**

Find the corner by using the max of row and column and calculate its value via closed 
form equation. Then depending on whether we used row or column and the parity of the 
spiral layer, add/ subtract the difference of the row and column to the corner value.

**Two Knights**

Count total ways to play two knights on a chessboard without counting attacks, and then 
subtract the number of invalid positions. There are k^2 * (k^2 - 1) / 2 ways of placing 
2 knights without considering attacks. Then there are (k - 1) * (k - 2) 2 x 3 blocks on
the board, each of which corresponds to 2 attacks. Multiply this by 2 to include 3 x 2
blocks. Can also think of each of the blocks as corresponding to 1 attack, and multiply 
by 8 for 8 directions that knight can attack, and divide by 2 for symmetry. Either way,
subtract 4 * (k - 1) * (k - 2).

**Two Sets**

Since the sum of 1...n is n(n + 1)/2, this number needs to be divisible by 2 in order to 
divide into two sets. This translates to n = 0, 3 mod 4. If n = 0 mod 4, divide 1..n into 
sequences of 4 numbers. First and last go into one set, and second and third go into the 
other set. This adds the same to each set. Similar method for n = 3 mod 4, except divide
3..n into sequences of 4 numbers and give one set 1, 2 and the other set 3.

**Bit Strings**

Binary exponentiation.

**Trailing Zeros**

Count the number of multiples of 5 that are part of n! This is equivalent to n / 5.
Then do same for 25, 125,...

**Coin Piles**

Make sure that one pile isn't more than twice the size of the other, otherwise it would
be impossible to empty that pile. Since each removal gets rid of 3 coins, also check that
the total number of coins is divisible by 3.

**Palindrome Reorder**

Count frequencies of each character and ensure that at most one has an odd frequency.
Then easiest to print characters in alphabetic order, possible middle element, then
reverse alphabetic order.

**Gray Code**

Use recursion. For each string in previous gray code, append 0, 1 or 1, 0. Swap the order
of the appends for each iteration. 


**Tower of Hanoi**

Use recursion. Move n - 1 disks to middle tower, move last disk to end tower. Then move
n - 1 disks from middle tower to end tower.

**Creating Strings**

Turn string into hashmap before backtracking to avoid repetitions.

**Apple Division**

Iterate through all possible subsets.

**Chessboard and Queens**

Standard backtracking algorithm. 

**Digit Queries**

If x <= 9 easy. Otherwise, subtract 1 from x to make everything 0-indexed.
For each length 1, 2,... subtract 9 * 10^length from x until no longer possible.
Then 10^length + x / length is the number the query hits, and x % len is the target
digit of the number 


**Grid Paths**

Backtrack. Key optimization is that if the path can no longer go straight but 
both sides are free return immediately. This is because no matter which way 
the path turns, it splits the Grid into two halves.