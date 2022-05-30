#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;                              //number of vertices
    vector<list<int>> adj;              //adjacency list
    
    public:
        Graph(int V){                   //Constructor
            this->V = V;        
            adj.resize(V);
        }
        
        void addEdge(int v, int w){
            adj[v].push_back(w);        //add w to v's list
        }
        
        void BFS(int s){                //s = source
            vector<bool> visited;
            visited.resize(V,false);
            list<int> queue;            //queue for BFS
        
            //Mark current node as visited and enqueue it
            visited[s] = true;
            queue.push_back(s);
            while(!queue.empty()){
                //Dequeue a vertex from queue and print it
                s = queue.front();
                cout << s << " ";
                queue.pop_front();
            
                //get all adjacent vertices of the dequeued vertex s. 
                //If an adjacent vertex is not visited,mark it visited & enqueue it
                for(auto adjacent:adj[s]){
                    if(!visited[adjacent]){
                        visited[adjacent] = true;
                        queue.push_back(adjacent);
                    }
                }
            }
        }
};

int main()
{
    int n, e, v, w, source;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> e;
    
    Graph g(n);
    
    cout << "Enter the edges : ";
    for(int i = 0 ; i < e ; i++){
        cin >> v >> w;
        g.addEdge(v,w);
    }
    
    cout << "Enter source node : ";
    cin >> source;
    cout << "BFS Traversal with source node as " << source << " : "; 
    g.BFS(source);

    return 0;
}
