**Distinct Numbers**

Straightforward set. Can also sort numbers and do linear scan.

**Apartments**

Go through each apartment in sorted order and greedily assign the cheapest apartment that they'll
take.

**Ferris Wheel**

Greedily pair heaviest and lightest children.

**Concert Tickets**

Store tickets in BST. Go through customers in sorted order and for each customer greedily 
assign the most expensive ticket that they'll accept. Note the use of set.lower_bound()--
gives the largest smaller element (if it exists).

**Restaurant Customers**

Assign arrival and leaving times as two separate events and combine all times into one array.
Then for each arrival add 1, and each departure subtract one. Max customers will be max 
prefix sum of this array.

**Movie Festival**

Greedily choose movies with the earliest possible end time. 

**Sum of Two Values**

2Sum. Easy hashmap.

**Maximum Subarray Sum**

Kadane's algorithm. Maintain cumulative sum, if it is ever negative, make it 0. If all numbers are
negative, return max of array. Note that max is compared before possibly setting current sum to 0.
This accurately calculates the max value in an all-negative array.

**Stick Lengths**

Cheapest option is to make every stick the median length.

**Missing Coin Sum**

Keep a variable that tracks the maximum value that coins can make. If a coin's value is greater 
than max_value + 1, then cannot make this value, so return max_value + 1. Otherwise, add the coins
value to max_value.

**Collecting Numbers**

Loop through numbers once. If reach n but haven't yet seen n - 1, need to do another pass.

**Collecting Numbers II**

Preprocess numbers using technique from part 1. Store numbers in one array, and store their 
positions in another. Then, for each query a, b: find the left number and the right number,
and store 4 booleans determining whether each numbers predecessor/ successor is before/ after it. 
Swap the positions of these two numbers and check the predecessors/ successors again. The left 
number might gain a predecessor or lose a successor when it moves to the right position. Similarly, 
the right number might lose a predecessor or gain a successor when it moves to the left position. 
Edge case to watch out for is when the left and right numbers are one apart, in which case 
gains/ losses are double counted, so adjust the delta by 1 in opposite direction to take care of 
this. 

**Playlist**

Two pointers. Left pointer corresponds to the left end of the subarray. Iterate through the right
endpoint. For each right value, check if it has been seen before and whether it was to the right
of the left pointer. If so, increase the left pointer to be one more than this last index.

**Towers**

Store current towers in BST. For each new cube, greedily choose the smallest possible tower
it could go on top of. If none exist, create a new tower with just that cube.

**Traffic Lights**

Maintain two BSTs, one for each interval's start and end, and one for the intervals size. First
one is used to add a traffic light, and the second is used to get the max size. This algorithm
works online, but there are more efficient offline implementations.

**Josephus Problem I**

Use policy based set to find child at index. Iterate n times, each iteration increase the current
index by 1, wrapping around if necessary (take mod current circle size). The next child to be 
removed from the circle is the one at this index.

**Josephus Problem II**

Same as part 1, but instead of incrementing current by 1, increment it by k.

**Nested Ranges Check**
**Nested Ranges Count**
**Room Allocation**

Go through guest in increasing order of arrival time. For each guest check if the 
most recently freed room was freed before this time. If so, reuse this room, resetting
the free time to be the guest's departure time. Otherwise, allocate another room. Rooms
are stores in a priority queue and sorted by decreasing free time.

**Factory Machines**

Binary search for the minimum possible value that satisfies condition. Condition being that desired
quantity can be produced. Note that initial right bound is the shortest time (fastest machine) times
the desired quantity.

**Tasks and Deadlines**

Greedily choose tasks with the shortest duration. 

**Reading Books**

If the maximum book is greater than the half the sum of the times of all the books, it forms a 
bottleneck since when one person reads that book, the other person can read every other book and 
would still have to wait. So in this case the total time is 2 * max. But if the maximum book
is less that half the total time, there is no bottleneck, so the total time is simply the sum
of the times. 

**Sum of Three Values**

Store the input numbers in a vector with their value and position. Then sort this vector by
increasing value. Iterate through vector with first pointer i, and then use two pointer method
with j and k to narrow down on a value that completes the sum. Overall O(n^2) runtime.

**Sum of Four Values**

Very similar to sum of three value but wrapped in another outer loop. Sort numbers and loop 
through two positions, i and j. Set k = j + 1, and l = n - 1, and use two pointers for
k and l to search for the target in linear time. Overall O(n^3) runtime.

**Nearest Smaller Values**

Monotonically increasing stack.

**Subarray Sums I**

Two pointer method. Increment right pointer, keeping track of subarray sum. If sum exceeds x,
increment left pointer until sum is less than x. If sum equals x, add 1 to counter.

**Subarray Sums II**

Since values can be negative, two pointer method no longer works. Instead, keep track of prefix
sums in a map. For each number v, add v to prefix sum and add the number of occurrences of 
(prefix sum - x) to the overall count. Then increment the count of the current prefix sum within
the map. Make sure that map is initialized to have 0 -> 1 to account for subarrays that start
at the beginning of the array. 

**Subarray Divisibility**

Very similar to subarray sums II. Since only care about values mod n, can store prefix sum counts 
in a vector of length n rather than a hashmap.

**Subarray Distinct Values*

Two pointers technique. Maintain map of counts of number of occurrences of all values seen within
pointers and a counter of the number of distinct values. Iterate over right pointer, and if
the number of distinct values is greater than k, increment the left pointer (updating map accordingly)
until the number of distinct values is less than or equal to k. At this point, increment the total
count by the length of the subarray. 

**Array Division**

Binary search. Initialize left to be the maximum element in the array, and right to be the sum
of values in the array. Then for each value mid, greedily check whether the array can be divided
into k subarrays each with a sum less than mid. O(nlog(n)) runtime. 

**Sliding Median**

Min heap/ max heap median maintenance problem. Since need fast deletions, use multiset instead
of priority queue. Max heap stores all elements less than the median and the min heap stores
all elements greater than the median. Invariant is that the size of the max heap must always be
the same size as the min heap, or at most 1 element larger. This ensures that the median is
always the largest element within the max heap. Insertions and deletions include rebalancing 
the two heaps to maintain this invariant. 

**Sliding Cost**

Exact same strategy as sliding median because the cheapest value to make all elements within a
window is the median of those elements. In addition to the two heaps, maintain the sum of the
elements in each heap. Update this sum as necessary when values are shifted around between the
two heaps. The median is the top of the max heap, and the total cost can be calculated by
(min_heap_sum - median * min_heap_size) + (median * max_heap_size - max_heap_sum).

**Movie Festival II**

Sort movies in increasing order of ending time and maintain a BST containing when each member
of the club is next free. Process movies by increasing end time, and for each movie see if there
is a club member who is free by the movie's start time. If so, greedily choose the member who is
free as late as possible (largest smaller element than movie start time). Then increment the 
number of movies watched and update this member's next free time to be when the current movie ends.
To find this latest free member (if exists), use lower_bound() on multiset sorted in reverse order. 

**Maximum Subarray Sum II**

Overall strategy is to create prefix sum array and for calculate the sliding window maximum for
every window of length k = b - a + 1. Thus, for each index left, want to find right index, namely 
the index in the range [left + a, left + b] that has the maximum prefix sum. This is found by using
pref[right] - pref[left - 1]. In practice, the algorithm iterates over the right indexes using
the sliding window monotonic queue technique. For each maximal right index, if it is large enough, 
the corresponding left index of the subarray is at index (right - b + 1). So to calculate the value
of this subarray, take pref[right] - pref[right - b], and then compare this with the global max.
O(n) runtime.