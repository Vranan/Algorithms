// Dijkstra Algorithm Geeks for Geeks

#include<iostream>
#include<limits.h>

#define V 9

using namespace std;

int minDistance(int dist[], bool sptSet[]) {
	int min = INT_MAX, min_index;
	
	for (int v = 0; v < V; v++) {
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v;
	}	
	return min_index;
}

void printDist(int dist[], int v) {
	cout << "Distance of Vertices from the source" << endl;
	for (int i = 0; i < v; i++)
		cout << "vertex i = " << i << ", distance = " << dist[i] << endl;
}

int dijkstra(int graph[V][V], int src) {
	
	int dist[V];
	int pred[V];
	
	bool sptSet[V];
	
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX, sptSet[i] = false; 
		pred[i] = -1;
	}
	dist[src] = 0;
	
	for (int count = 0; count < V-1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++) {
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) 
			{ 
				dist[v] = dist[u]+graph[u][v];
				pred[v] = u;
			}
	   }
	}
	
	for (int i  = 0; i < V; i++)
		cout << "i = " << i << ", pred = " << pred[i] << endl;
	printDist(dist, V);
	return 0;
}	


int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}

