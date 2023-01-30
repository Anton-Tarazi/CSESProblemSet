**Static Range Sum Queries**

Prefix sum array: sum(a ... b) =  pref_sum[b] - pref_sum[a - 1]

**Static Range Minimum Queries**

Use sparse table. With O(n log n)  preprocessing create a 2d array sparse_table where
sparse_table[i][j] = min(arr[j], arr[j + 1], ... arr[2^j - 1]). This means calculate
minimum for all subarrays whose length is a power of 2. From this the minimum of 
any subarray can be calculated in O(1) time by breaking up each query into two
(possibly overlapping) subarrays of a length which is a power of 2 and can thus
be looked up in the sparse table. 

**Dynamic Range Sum Queries**

Segment tree. Find largest power of 2 greater than or equal to the length of the array,
then make segment tree double this size. Treat array as though it is of this (likely
larger) length. Note that problem is 1-indexed but algorithm is designed for 0-indexed 
segment tree, so must decrement all query indices by 1.

**Dynamic Range Minimum Queries**

Very similar to dynamic range sum. Use segment tree, and round up array to nearest
power of two, treating it as though it is this length. Again make sure to account
for fact that segment tree implementation treats array as 0-indexed, but problem
is 1-indexed. 

**Range Xor Queries**

Xor is the inverse of xor, so just use prefix xor array. xor(a ... b) = 
pref_xor[b] ^ pref_xor[a - 1]

**Range Update Queries**

Store a difference array, an array whose prefix sum equals the original array. For
each range update, increment diff_arr[a] by u, and decrement diff_arr[b] by u. The 
value of an element k is then sum(diff_arr[1], ... , diff_arr[k]). To quickly 
calculate the sum, store the difference array in a binary indexed tree. Then updates
and queries both run in O(log n).

**Forest Queries**
**Hotel Queries**
**List Removals**
**Salary Queries**
**Prefix Sum Queries**
**Pizzeria Queries**
**Subarray Sum Queries**
**Distinct Values Queries**
**Increasing Array Queries**
**Forest Queries II**
**Range Updates and Sums**
**Polynomial Queries**
**Range Queries and Copies**
