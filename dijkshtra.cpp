#include <bits/stdc++.h>
using namespace std;

int graph[10][10];

int min_Key(int key[], bool Mst_Set[], int V)
{
   
    int min_index;
    int min = INT_MAX;
    for(int i = 0 ; i < V ; i++)
    {
        if(key[i] < min && Mst_Set[i] == false)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMst(int graph[][10], int parent[], int V)
{
    cout<<"Edge -- Weight\n";
    for(int i = 1 ; i < V ; i++)
    {
        cout << parent[i] << " -> " << i << "\t" << graph[i][parent[i]] << endl; 
    }
}

void dij(int graph[][10], int V)
{
    int parent[V];
    int key[V];
    bool Mst_Set[V];            //to keep track of vertices already included in mst
    for(int i = 0 ; i < V ; i++)
    {
        key[i] = INT_MAX;
        Mst_Set[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int j = 0 ; j < V-1 ; j++)          //while mst set doesn't include all vertices
    {
        int u = min_Key(key,Mst_Set,V);         //u is not included in mst set and has minimum value
        Mst_Set[u] = true;
        for(int v = 0 ; v < V ; v++)
        {
            if(graph[u][v] && Mst_Set[v]==false && key[u]!=INT_MAX && (graph[u][v]+key[u])<key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v]+key[u];
            }
        }
    }
    printMst(graph,parent,V);
}

int main()
{
    int V,e;
    int u,v,w;
    
    cout << "Enter no. of vertices : ";
    cin >> V;
    
    cout << "Enter no. of edges : ";
    cin >> e;
    cout << "Enter edges of graph with their weight : ";
    
    for(int i = 0 ; i < e ; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    dij(graph,V);
    return 0;
}
