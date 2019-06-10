#include <stdio.h> 
#include <iostream>
#include <limits.h> 

using namespace std;

int minDistance(int* dist, bool* sptSet, int* prev, int V) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index;
   
    for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
        	min = dist[v], min_index = v;
   
    return min_index; 
} 
   
// A utility function to print the constructed distance array 
int printSolution(int* dist, int* prev, int V) 
{ 
    printf("\n"); 
    for (int i = 0; i < V; i++){
    	printf("\nSource ---------> Vertex %d => distance: %d\n", i+1, dist[i]);
	    cout << "path:\t";
		
		int tmp[V];
		int m = i;
		for(int j = 1; j < V; j++){
			m = prev[m];
			tmp[j] = m;
		}
		tmp[0] = i;
		bool p = false;
		for(int j = V-1; j >= 0; j--){
			if(dist[i] == 0 && p == false){
				cout << " vertex 1";
				p = true;
			}
				
			if(tmp[j] != tmp[j-1])
				cout << " vertex " << tmp[j]+1;
		}
	}
} 

void dijkstra(int** graph, int src, int V) 
{ 
    int *dist = new int[V];
    bool *sptSet = new bool[V];
    
    int *prev = new int[V];
    
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false, prev[i] = 0;

    dist[src] = 0; 
   
    // Find shortest path for all vertices 
    for (int count = 0; count < V-1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet, prev, V); 
   
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
   
	    // Update dist value of the adjacent vertices of the picked vertex.
		// Relax 
    	for (int v = 0; v < V; v++) 
    		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
            	                           && dist[u]+graph[u][v] < dist[v]){
            	dist[v] = dist[u] + graph[u][v];
            	prev[v] = u;
            }
            	
    } 
   
    // print the constructed distance array 
    printSolution(dist, prev,V); 
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
