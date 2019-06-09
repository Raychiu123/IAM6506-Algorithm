#include <stdio.h> 
#include <iostream>
#include <limits.h> 

using namespace std;

int minDistance(int* dist, bool* sptSet, int V) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
   
    for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
        	min = dist[v], min_index = v; 
   
    return min_index; 
} 
   
// A utility function to print the constructed distance array 
int printSolution(int* dist, int n, int V) 
{ 
    printf("\n\n"); 
    for (int i = 0; i < V; i++) 
    	printf("Source ---------> Vertex %d => distance: %d\n", i+1, dist[i]); 
} 

void dijkstra(int** graph, int src, int V) 
{ 
    int *dist = new int[V];
    bool *sptSet = new bool[V];
    
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 

    dist[src] = 0; 
   
    // Find shortest path for all vertices 
    for (int count = 0; count < V-1; count++) { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet, V); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
    // Update dist value of the adjacent vertices of the picked vertex. 
    for (int v = 0; v < V; v++) 
    	if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
    } 
   
    // print the constructed distance array 
    printSolution(dist, V, V); 
} 

int main() 
{ 
	int vertex;
	cout << "vertex num = "; cin >> vertex;

    int** adj_mtx = new int*[vertex];
    for(int i = 0; i < vertex; ++i) adj_mtx[i] = new int[vertex];
    
    for(int i = 0; i < vertex; i++){
    	for(int j=0; j<vertex; j++){
    		cout << "adj_matrix[" << i+1 << "][" << j+1 << "]=\t";
    		try{
    			cin >> adj_mtx[i][j];
    			if(adj_mtx[i][j] < 0)
    				throw 0;
			}
			catch(...){
				cout << "Dijksta's alg doesn't deal with negative weight!\n";
				return 0;
			}
			
		}
	}
       
    dijkstra(adj_mtx, 0, vertex); 
   
    return 0; 
} 
