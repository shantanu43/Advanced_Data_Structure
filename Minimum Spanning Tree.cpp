
#include <bits/stdc++.h>
using namespace std;
// a structure to represent a
// weighted edge in graph


class Edge 
{
	public:
	int src, dest, weight;
};
// a structure to represent a connected,
// undirected and weighted graph

class Graph 
{
	public:
	// V-> Number of vertices, E-> Number of edges
	int V, E;
	
	// graph is represented as an array of edges.
	// Since the graph is undirected, the edge
	// from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	Edge* edge;
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}
// A structure to represent a subset for union-find
class subset 
{
	public:
	int parent;
	int rank;
};
// A utility function to find set of an element i
// (uses path compression technique)

int find(subset subsets[], int i)
{
	// find root and make root as parent of i
	// (path compression)
	if (subsets[i].parent != i)
	subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
// A function that does union of two sets of x and y
// (uses union by rank)

void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	// Attach smaller rank tree under root of high
	// rank tree (Union by Rank)
	
	if (subsets[xroot].rank < subsets[yroot].rank)
	subsets[xroot].parent = yroot;
	
	else if (subsets[xroot].rank > subsets[yroot].rank)
	subsets[yroot].parent = xroot;
	// If ranks are same, then make one as root and
	// increment its rank by one
	else 
	{
	subsets[yroot].parent = xroot;
	subsets[xroot].rank++;
	}
}
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges

int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;

}
// The main function to construct MST using Kruskal's
// algorithm
void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V]; // Tnis will store the resultant MST
	int e = 0; // An index variable, used for result[]
	int i = 0; // An index variable, used for sorted edges
	// Step 1: Sort all the edges in non-decreasing
	// order of their weight. If we are not allowed to
	// change the given graph, we can create a copy of
	// array of edges
	
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	// Allocate memory for creating V ssubsets
	subset* subsets = new subset[(V * sizeof(subset))];
	
	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
	subsets[v].parent = v;
	subsets[v].rank = 0;
	}
	// Number of edges to be taken is equal to V-1
	while (e < V - 1 && i < graph->E)
	{
		// Step 2: Pick the smallest edge. And increment
		// the index for next iteration
		
		Edge next_edge = graph->edge[i++];
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		
		// If including this edge does't cause cycle,
		// include it in result and increment the index
		// of result for next edge
		
		if (x != y) 
		{
		result[e++] = next_edge;
		Union(subsets, x, y);
		}
		// Else discard the next_edge
	}
	// print the contents of result[] to display the
	// built MST
	cout << "Following are the edges in the constructed "
	"MST\n";
	
	int minimumCost = 0;
	for (i = 0; i < e; ++i)
	{
	cout << result[i].src << " -- " << result[i].dest
	<< " == " << result[i].weight << endl;
	minimumCost = minimumCost + result[i].weight;
	}
	// return;
	cout << "Minimum Cost Spanning Tree: " << minimumCost
	<< endl;
}


int main()
{
	
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	Graph* graph = createGraph(V, E);
	
	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;
	
	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;
	
	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;
	
	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;
	
	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;
	
	// Function call
	KruskalMST(graph);
	return 0;
}

/*
OUTPUT

Following are the edges in the constructed MST
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Cost Spanning Tree: 19
*/
//Prims algo:

#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define V 5
// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST

int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	if (mstSet[v] == false && key[v] < min)
	min = key[v], min_index = v;
	return min_index;
}
// A utility function to print the
// constructed MST stored in parent[]

void printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
	cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation

void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];
	// Key values used to pick minimum weight edge in cut
	int key[V];
	// To represent set of vertices included in MST
	bool mstSet[V];
	// Initialize all keys as INFINITE
	
	for (int i = 0; i < V; i++)
	key[i] = INT_MAX, mstSet[i] = false;
	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST
	// The MST will have V vertices
	
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);
		// Add the picked vertex to the MST Set
		mstSet[u] = true;
		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)
		// graph[u][v] is non zero only for adjacent vertices of m
		// mstSet[v] is false for vertices not yet included in MST
		// Update the key only if graph[u][v] is smaller than key[v]
		if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
		parent[v] = u, key[v] = graph[u][v];
		
	}
	// print the constructed MST
	printMST(parent, graph);
}
// Driver code
int main()
{
	
	int graph[V][V] = 
	{ { 0, 3, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 6, 0, 0, 7 },
	{ 6, 8, 0, 0, 8 },
	{ 0, 7, 7, 11, 0 } };
	// Print the solution
	primMST(graph);
	return 0;
}

