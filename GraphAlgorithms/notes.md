**Counting Rooms**

Simple dfs connected components check.

**Labyrinth**

BFS. Encode directions/ which rooms have been visited within the maze itself. After BFS, if the 
target square is undiscovered, return no. Otherwise, backtrack through the directions in maze
until reaching started room, then reverse this sequence.

**Building Roads**

DFS connected components check. For each component save a representative city in a list.
Build a new road between consecutive cities in the list to connect all cities.

**Message Route**

Standard old BFS.

**Building Teams**

Bipartite matching. Use dfs.

**Round Trip**

DFS cycle detection. Iterate through all connected components, and for each check if there is
a big enough cycle. Pass step parameter into dfs which can be compared to that of a visited node
to ensure that cycle is big enough. dfs function has 3 return types: -1 means cycle has not been
found yet, 0 means cycle has already been found and fully printed, and >= 1 means that function
call is in the midst of a cycle and should print its node.

**Monsters**

First run bfs from each monster to calculate the number of steps for the nearest monster to get
to of each room. Then run dfs from player, making sure that every room is entered in fewer steps
than a monster can get there. Use backtracking to produce a route.

**Shortest Routes I**

Classic Dijkstra's algorithm.

**Shortest Routes II**

Floyd-Warshall Algorithm.


**High Score**

Extremely tricky. Main idea is Bellman-Ford but since need max path, negate all edge lengths 
and then negate final answer. Als need to watch out for negative cycles, but only on nodes
that are on the path from room 1 to n. For this, conduct dfs from room 1 and dfs on the 
reverse graph from node n. Then on the nth iteration of B-F, if any of these rooms have a
lower weight there is a relevant negative cycle (because negative cycles that can't be
reached on the way from 1 to n don't matter).


**Flight Discount**

For each city, create two nodes - one representing having a coupon and one represent not having
a coupon. Then for each edge from a -> b at cost 3, add 3 edges to this new graph: (a coupon) 
-> (b no coupon) at cost c, (a coupon) -> (b no coupon) at cost c / 2, (a no coupon) ->
(b no coupon) at cost c. Then perform Dijkstra's algorithm from (1 coupon) to (n no coupon).


**Cycle Finding**

Run Bellman-Ford while maintaining the predecessor of each node. If on the nth iteration, 
any node's distance decreases - that node must be reachable from a negative cycle.
Therefore, following the predecessor list from this node will result in a cycle, so use 
slow - fast pointer algorithm to find a node in the cycle. Then from this new node, continue
traversing predecessors until see that node again, storing each node encountered. This
list is the cycle backwards. 


**Flight Routes**

Weird version of Dijkstra's algorithm. Rather than a visited/ processed array, have a counts
array that stores the number of times each node has been seen. There is also no distances array
and distances are only stored within the priority queue. On each iteration, pop the closest node
from the queue, and if it hasn't been visited k times already update the distance for ALL of its
neighbors and add them to the queue. Whenever node n is popped from the q, found the next shortest
path to it, so print distance and break once k paths have been found.

**Round Trip II**

Similar strategy to Round Trip I. Encode in visited array the last step where the node was seen, or -1
if the node has been completely processed and no cycle has been found. Since the path is printed in
backwards order, every edge in the graph is also reversed. This results in the path being printed
in the correct order. 

**Course Schedule**

Topological sorting. Use dfs and check for cycles since input is not necessarily a DAG.

**Longest Flight Route**

Since graph is DAG, do DP/ dfs through nodes where dp[v] = longest path from v to n or -1 if 
no such path exists. To calculate dp[v], recurse on all outgoing edges, and find the maximum
path among those. Each function call also stores a link from the current node to the neighbor
that produced the longest path. 

**Game Routes**

DFS. The path number of paths from any node to node n is the sum of the paths the 
node's neighbors to n. Save calculations in array each time. Base case is there 
is only 1 path from node n to node n.

**Investigation**

Modified Dijkstra. For every node processed, update distances of neighboring nodes. If new distance
is smaller than old distance, reset distance counts, min flights, and max flights. But if new 
distance is the same as the old distance, update counts, min flights, and max flights.

**Planets Queries I**
**Planets Queries II**
**Planets Cycles**
**Road Reparation**

Minimum spanning tree. Using Kruskal's algorithm.

**Road Construction**

Union find. 

**Flight Routes Check**
**Planets and Kingdoms**
**Giant Pizza**
**Coin Collector**

Note that able to collect every coin within a strongly connected component. So use Kosaraju's 
algorithm to construct meta-DAG where the value of each meta-node is the sum of the values of 
the nodes in the corresponding SCC. Then use dfs/ dynamic programming on the meta-DAG to 
determine the max value path. This is simple since there are no cycles.

**Mail Delivery**
**De Bruijn Sequence**
**Teleporters Path**
**Hamiltonian Flights**

Store edges in adjacency matrix where mat[a][b] = number of flights from city a to city b. Solve
problem using subset dynamic programming, where dp[i][j] = number of Hamiltonian flights from city
1 to city j using the cities in subset i (note that for this to be valid/ nonzero, j must be an
element of i). i is encoded such that if the xth bit is set, i contains the (x + 1)th city. This 
means that city 1 is not encoded because it is assumed to be in every subset (ie only consider 
subsets that contain city 1, so no explicitly include it). To calculate dp[i][j], iterate over
all nodes k that are in i - {j}, and find dp[i - {j}][k], which is the number of Hamiltonian
paths from city 1 to city k using the cities in subset i except j. Each of these paths can be
extended by the flights from k -> j to be a path from 1 -> j using subset i. Therefore
dp[i][j] = sum(dp[i - {j}][k] * mat[k][j] for k = 2, ... n).

**Knight's Tour**

Hamiltonian path, solve with dfs/ backtracking. To optimize, always choose the next available
square with the fewest number of follow-up moves. 

**Download Speed**
**Police Chase**
**School Dance**
**Distinct Routes**