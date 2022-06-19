//Bipartite graph using dfs
#include <bits/stdc++.h>
using namespace std;

bool dfs_bipartite(vector<vector<int>> &graph, int node, vector<int> &color){
    for(int neigh : graph[node]){
        if(color[neigh] == -1){
            color[neigh] = 1 - color[node];
            if(!dfs_bipartite(graph,neigh,color))
                return false;
        }else{
            if(color[neigh] == color[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph, int n){
    vector<int> color(n,-1);
    for(int i = 0 ; i < n ; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!dfs_bipartite(graph,i,color))
                return false;
        }
    }return true;
}


int main()
{
    int n,e,u,v;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for(int i = 0 ; i < n ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }if(isBipartite(graph,n))
        cout << "The graph is bipartite" << endl;
    else
        cout << "The graph is not bipartite" << endl;

    return 0;
}
