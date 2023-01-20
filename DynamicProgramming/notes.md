**Dice Combinations**

1D dynamic programming. dp[i] = number of ways to roll i. dp[i] = sum(dp[i - 1], ..., dp[i - 6])

**Minimizing Coins**

2D dynamic programming in 1D space. dp[i] = min number coins to create i. Iterate through
dp[i - c] for all coins c to calculate.

**Coin Combinations I**

Simple dp. dp[i] = number of ways to get sum of i. dp[i] = sum(dp[i - c] for c in coins).

**Coin Combinations II**

dp[i][j] = number of unique to get sum j using coins 1..i. Initialize dp[i][0] = 1, since there
is always 1 way of getting a sum of 0. To calculate dp[i][j], either don't include ith coin,
or include the ith coin: dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]. Note that second part
of sum is dp[i], not dp[i - 1] since can use many copies of one coin. Because coins are considered
in order, (unlike part I), each combination is only counted once.

**Removing Digits**

Greedily remove the maximum digit until reaching 0. This isn't really a dynamic programming
problem.

**Grid Paths**

2D dp. dp[i][j] = number of paths from (i, j) to (n, n). Note that dp array is 1-indexed and that
it is "initialized" with dp[0][1] = 1, because this allows the first iteration of the double for
loops to properly set dp[1][1] = (Grid[1][1] == '.'). dp[1][0] = 1 would have worked as well.


**Book Shop**

Classic knapsack. dp[i][j] = max number of pages can buy from books 1...i with budget j. For each
book, either don't buy it: dp[i][j] = dp[i - 1][j]; or buy it: 
dp[i][j] = dp[i - 1][j - prices[i]] + pages[i]. Choose the max of the two, unless not enough money
to buy it, so have to do first option.

**Array Description**

2D dynamic programming. dp[i][j] = number of arrays of length (i + 1) ending with the number (j + 1).
Note that dp is initialized with the first entry of the array. The transition function takes the sum
of the 3 elements directly above for the entire row if nums[i] = 0, or just for the (nums[i] - 1)th 
entry if nums[i] != 0.

**Counting Towers**

fused[i] = number of towers of length i where the end block is fused. separate[i] = number of
towers of length i where the end blocks are separate. To calculate separate[i], can either take
separate[i - 1] and extend left block up, extend right block up, extend both blocks up, or
add two new 1x1 blocks on top; or take fused[i - 1] and add two new 1x1 blocks on top. So
separate[i] = 4 * separate[i - 1] + fused[i - 1]. For fused[i], can either take fused[i - 1]
and extend the whole thing up or place a new 2x1 block on top; or take separate[i - 1] and
place a new 2x1 block on top. So fused[i] = 2 * fused[i - 1] + separate[i - 1]. The key insight
is that subproblems can be created by extending the topmost blocks of smaller subproblems,
rather than just plopping blocks on top.

**Edit Distance**

Standard 2D dp. If characters are the same, take value without those characters. Otherwise take
min of change, insert, or remove.

**Rectangle Cutting**

2D dp. dp[i][j] = min number of cuts for i x j square. Try all possible cuts in x and y 
directions. O(n^3) runtime. Optimization by only calculating dp[i][j] when i >= j, and then
just copying this value into dp[j][i]. 

**Money Sums**

2D dp. dp[i] = true/false if sum i can be made. Optimized using bitset. For each x, shift bitset
x to left and OR with itself. This is equivalent to iterating through all coins c and setting
dp[i] |= dp[i - c].


**Removal Game**

dp[i][j] = {player 1 max score for subarray i...j, player 2 max score for subarray i...j}. Depending
on the parity of the length of the subarray, it is either player one or player two's turn. For each,
maximize the respective part of dp[i][j], by either taking the left endpoint or the right endpoint.
So dp[i][j].player = max(nums[i] + dp[i + 1][j].player, nums[j] + dp[i][j - 1].player), where
player alternates between first and second. Note that outer for loop has to run backwards for this
type of subarray dp to work.

**Two Sets II**

2D dp with 1D space optimization. 2D version is dp[i][j] = number of ways of producing a subset with
value i, using the numbers 1...j. Recurrence relation is dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1].
This has been optimized to a 1D array where dp[i] = number of ways of producing a subset with value i.
To avoid double counting, calculate dp[i] from right to left. Note also that dp[i] is not calculated
within a single iteration of the double for loops, but rather incrementally updated. The subset sum
which gives answer is dp[n * (n + 1) / 2] since that is half of sum(1..n), but because dp[i] 
gives the number of subsets, and one subset uniquely determines the other, the answer is
dp[n * (n + 1) / 2] / 2. However, since taking answer mod 1e9 + 7, cannot just divide by 2 but 
rather must multiply by the inverse of 2 mod 1e9 + 7.

**Increasing Subsequence**

Easy O(n^2) dp, but need to do something better given input size. Maintain vector of current 
longest increasing subsequence. For each number x processed, if x is larger than the end of
the vector, append x. Otherwise, replace the smallest element greater than or equal to x in 
the vector with x. The reason this works is that shrinking the value of elements where possible
opens up more options for further elements to be appended to the subsequence. Since the vector
is in increasing order, this smallest larger element can be found via binary search. .

**Projects**

Sort projects in increasing order of ending time. dp[i] = max reward from attending subset of
projects from 1...i. To calculate dp[i], either don't attend the current project, so or attend 
the current project, in which case need to find dp[j], where j is the last project that ends 
before project i starts. Since the projects are sorted, index j can be found using binary search 
on the projects array. So dp[i] = max(dp[i - 1], reward[i] + dp[j]).

**Elevator Rides**

Subset bitmask dp. dp[i] = {min rides for subset i, weight of last ride for subset i}. To calculate
dp[i], iterate over all set bits j and consider dp[i \ j]. Either the person at weights j can 
be added to the last ride, so dp[i] = {dp[j].first, dp[j].second + weights[j]}, or the person
is too heavy and must take a new ride: dp[i] = {dp[j].first + 1, weights[j]}. After iterating
over all j, dp[i] will take the value that minimizes dp[i].first, and on ties minimizes 
dp[i].second.

**Counting Tilings**
**Counting Numbers**