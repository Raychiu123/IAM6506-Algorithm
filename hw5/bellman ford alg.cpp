#include <stdio.h> 
#include <iostream>
#include <limits.h> 

using namespace std;

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

bool bellman_ford(int** w, int source, int V)
{
    int* d = new int[V];              
	int* parent = new int[V];
	
    for (int i=0; i<V; i++) d[i] = 1e9;
 	
    d[source] = 0;				// 設定起點的最短路徑長度
    parent[source] = source;    // 設定起點是樹根（父親為自己）
    for (int i=0; i<V-1; i++){   // 重覆步驟V-1次
        for (int a=0; a<V; ++a){ // 全部的邊都當作捷徑
            for (int b=0; b<V; ++b){
                if (d[a] != 1e9 && w[a][b] != 1e9){
                    if (d[a] + w[a][b] < d[b])
                    {
                        d[b] = d[a] + w[a][b];
                        parent[b] = a;
                    }
				}
			}
		}
	}
                    
    for (int a=0; a<V; ++a){
        for (int b=0; b<V; ++b){
            if (d[a] != 1e9 && w[a][b] != 1e9){
                if (d[a] + w[a][b] < d[b]){
					cout << "negative cycle!";
					return false;
				}
			}
		}
	}     
    printSolution(d, parent, V);
    return true;
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
    		cin >> adj_mtx[i][j];
		}
	}
       
    bellman_ford(adj_mtx, 0,vertex); 
   
    return 0; 
} 
