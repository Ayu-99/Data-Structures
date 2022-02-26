class Solution {
    // Node to maintain state in Queue
	// At any point of time, we should store 3 things
    // current node, distance travelled and nodes visited till now.
    class Node {
        int visited;
        int dist;
        int node;
        Node(int node, int dist, int visited) {
            this.node = node;
            this.dist = dist;
            this.visited = visited;
        }
    }
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
		// This is to eliminate repetitive steps
        Set<Integer>[] visited = new HashSet[n];
		// Queue to process in BFS
        Queue<Node> queue = new LinkedList<>();
		// Since we can start from any node,
		// we store every node and state in Queue.
        for(int i = 0; i < n; i++) {
            visited[i] = new HashSet<>();
			// since constraints are very small, we can maintain visited nodes in integer
			// suppose n = 3, and we have visited 0th node the visited's value in binary is 001
			// if we visit node 1, then visited's value in binary is 010
			// if we visited nodes 0 and 2, then visited's value in binary is 101
			// This is how we represent visited nodes.
            queue.add(new Node(i, 0, 1 << i));
            visited[i].add(1 << i);
        }
		// BFS
        while(!queue.isEmpty()) {
			// poll node from queue
            Node node = queue.poll();
			// for n = 3, if we visit all nodes then visited's value in binary is 111 = 7
			// for n = 2, if we visited all nodes then visited's value in binary is 11 = 3
			// so, generally, the formula for visiting all nodes is (2 ^ n) - 1
			// if we see visited's value as  2 ^ n - 1,
			// then we know that we have visited all nodes. So, return 
            if(node.visited == (1 << n) - 1) 
                return node.dist;
			// visited neighbor nodes
            for(int nei : graph[node.node]) {
			    // calculate new visited's value
                int mask = node.visited | (1 << nei);
				// if new visited's value is not in queue,
				// add that to queue.
                if(visited[nei].add(mask)) 
                    queue.add(new Node(nei, 1 + node.dist, mask));
            }
        }
        return -1;
    }
}
