#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&graph,int s, int n, vector<bool> &visited){
    visited[s] = true;
    cout << s << " ";
    
    for(int i = 0 ; i < graph[s].size(); i++){
        int adjacent = graph[s][i];
        if(!visited[adjacent])
            DFS(graph, adjacent, n, visited);
            
    }
}

int main()
{
    int n,e,source,v,w;
    cout << "n = ";
    cin >> n;

    cout << "e = ";
    cin >> e;
    
    vector<vector<int>> graph(n);
    for(int i = 0 ; i < e ; i++){
        cout << " v and w : ";
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
        
    }cout << "source = ";
    cin >> source;
    vector<bool> visited(n,false);
    cout << "DFS with source " << source << " : ";
    DFS(graph,source, n, visited);
    

    return 0;
}
