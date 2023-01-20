**Josephus Queries**
**Exponentiation**

Iterative binary exponentiation. Whenever b has a 1 bit in position j, multiply the result by
a^(2^j). a^(2^j) is calculated by (a^(2^(j - 1)))^2. For this reason, go through bits from
least to most significant. 

**Exponentiation II**

Modular iterative binary exponentiation twice. First calculate x = b^c % (MOD - 1) and then
calculate a^x % MOD. Reduce the exponent mod (MOD - 1) because of Fermat's Little Theorem.

**Counting Divisors**

Create an array divisors of max needed length where divisors[i] = number of divisors for i.
Calculate this by iterating over 1... MAX X and then iterating over each multiple less than 
MAX X and incrementing divisors. Then just query array.

**Common Divisors**
**Sum of Divisors**

For each divisor i, the number of times it occurs from 1 to n is n / i. So the answer is 
sum((n / i) * i for i in range(1, ... n)). To compute this in O(sqrt(n)), note that there
are only O(sqrt(n)) distinct values of n / i. For i = 1...sqrt(n), calculate total directly,
but for i = sqrt(n)...n, maintain left and right counters and then use arithmetic 
progression sum to calculate the number of values that sum to this value. Then add this to
the total. 


**Divisor Analysis**

Finding number and sum of divisors is straightforward. Those are arithmetic multiplicative functions
tau and sigma. Finding the product of the divisors is extremely tricky. Note that for a number n,
can write out the divisors [1, ... n], and group them into pairs that multiply to n. So the product
of divisors of n is n^(tau(n)/2). This is tricky for two reasons, first of all: working mod so need
to be careful with division. Second, there is the case of n being a perfect square (all exponents are 
even), so tau(n) is not divisible by 2. Maintain a flag that keeps track of whether all exponents
seen so far are even. Also maintain the number, and its square root, modulo MOD. And keep track
of the number of divisors modulo (MOD - 1) (tau, but taken in a different modulo than the tau for
the first part of the problem. Since eventually this tau will be used in an exponent, it takes this
remainder by Fermat's Little Theorem). At the first odd exponent, if any, divide this special tau by 2. 
Then after the loop, if no odd exponent was seen, the number is a perfect square, so the product
of divisors is the square root raised to the power of the special tau. Otherwise, an odd exponent
was seen, so tau was already properly divided by 2, and the product of divisors is the number
raised to the power of special tau. 

**Prime Multiples**

First note that n/a (floor division) gives how many numbers up to n are divisible by a. So,
iterate over all subsets of the primes, and divide n by the product of each subset to see how
many numbers are divisible by every product of the primes. Using inclusion-exclusion principle, 
depending on whether the size of the subset is odd/even, add or subtract this value from the 
total.

**Counting Coprime Pairs**
**Binomial Coefficients**

Precompute all factorials, then find a!, b!, and (a - b)! in constant time. Multiply b! and (a - b)!
and since working mod 1e9 + 7, find the modular inverse of the denominator and multiply this with a!.

**Creating Strings II**

Answer is multinomial coefficient (n / c1, c2, ..., c26) = n! / (c1! x ... c26!) where n is the 
length of the string and c1...c26 are the frequencies of the characters a...z. Since everything is
mod 1e9 + 7, instead of dividing need to multiply by inverse. Multiplicative inverse of x is 
calculated using binary exponentiation/ Fermat's Little Theorem.

**Distributing Apples**

Consider all n children lined up in a row. Starting at the leftmost child, distributing m
apples can be though of us a string of ->,'s and o's. Where -> means move one child to the right
and o means give the child an apple. There are m o's and n - 1 ->'s, so the length of the string
is n + m - 1, and the solution is the number of ways of choosing m positions to be o within this
string. This is the binomial coefficient (n + m - 1) choose (m).

**Christmas Party**

Counting derangements - permutations where no element appears in its original place. dp[i] is
the number of derangements of 1...i. dp[i] = (i - 1) * (dp(i - 2) + dp(i - 1)). Consider how the 
element 1 moves in the derangement. There are i - 1 ways to choose an element x that replaces 1.
Either replace element x with element 1, which results in having to create a derangement of the 
remaining i - 2 elements. Or replace x with an element other than 1, which results in having to
create a derangement of the remaining i - 1 elements.

**Bracket Sequences I**

Catalan numbers. If n is odd, return 0 otherwise return n/2th Catalan number.

**Bracket Sequences II**

Scan input string, if at any point the number of right parentheses is greater than the number of
left, or either number is greater than n / 2, then it is impossible to construct a valid string,
so return 0. Otherwise, calculate how many left parentheses and how many right are needed to 
complete the string, and find their difference need_right - need_left. Note that this difference
will always be positive (or 0), since a negative difference would mean that the prefix parentheses
were invalid. There are (n - k) choose need_left (or n - k choose need_right will give the same
result) ways of choosing these left and right parentheses. Invalid choices will be those where there
is a prefix of rights that exceeds the number of lefts by diff. Flipping all parentheses in this
invalid prefix uniquely creates a string of length (n - k) with (need_left + diff + 1) left
parentheses. So the number of invalid ways of completing the prefix is (n - k) choose (need_left +
diff + 1). Subtracting this from the number of ways to choose parenthesis arbitrarily gives the
answer.


**Counting Necklaces**

Use Burnside's Lemma / orbit counting theorem. Idea relies on group theory.

**Counting Grids**
**Fibonacci Numbers**

Binary matrix exponentiation.

**Throwing Dice**

The dynamic programming solution to this problem is dp[i] = number of ways to roll score of i, and
dp[i] = sum(dp[i - 1] + ... + dp[i - 6]). But this is too slow for the constraints, so instead use
6x6 linear recurrence matrix and binary matrix exponentiation. The transition matrix looks like:\
[0 1 0 0 0 0]\
[0 0 1 0 0 0]\
[0 0 0 1 0 0]\
[0 0 0 0 1 0]\
[0 0 0 0 0 1]\
[1 1 1 1 1 1]

After raising to the power of n, the bottom right corner contains the solution. 

**Graph Paths I**

Represent graph as adjacency matrix M. Then M^k[0][n - 1] contains the number of length-k
paths from node 1 to n. M^k can be efficiently calculated using binary exponentiation.

**Graph Paths II**

Represent graph as adjacency matrix M. M[a][b] = {edge cost from a -> b if exists, else INF}. 
M^k[0][n - 1] contains the min cost length-k path from node 1 to n. Multiplication is defined
differently: AB[i][j] = min_k(A[i, k] + B[k, j]). This minimizes the lengths of paths rather
than combining them. M^k can still be efficiently calculated using binary exponentiation. 

**Dice Probability**

2D dp. dp[i][j] = probability of getting sum of j with i dice. 
dp[i][j] = 1/6 * dp[i - 1][j - 1] + ... + 1/6 * dp[i - 1][j - 6]

**Moving Robots**
**Candy Lottery**

Expected value of max of n {1...k} uniform random variables. There are n^k possible 
combinations for the candy distributions, and for each i = 1, ..., k in precisely 
i^n - (i - 1)^n of those combinations is the maximum candy for a child i. This can
be thought of as the volume of the half-shell around an i x i x ... i n-dimensional
hypercube. 

**Inversion Probability**
**Stick Game**
**Nim Game I**
**Nim Game II**
**Stair Game**
**Grundy's Game**
**Another Game**