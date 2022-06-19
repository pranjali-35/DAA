//Cycle detection in undirected graph
#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &graph, int s, vector<bool> &visited){
    int n = graph.size();
    vector<int> parent(n,-1);
    queue<pair<int,int>> q;
    visited[s] = true;
    q.push({s,-1});
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto neigh:graph[node]){
            if(!visited[neigh]){
                visited[neigh] = true;
                q.push({neigh,node});
            }else if(par != neigh)
                return true;
        }
    }return false;
}

bool detectCycle(vector<vector<int>> &graph){
    int n = graph.size();
    vector<bool> visited(n,false);
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            if(isCycle(graph,i,visited))
                return true;
        }
    }return false;
}

int main()
{
    int n,e,u,v;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for(int i = 0 ; i < e ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }bool cycle = detectCycle(graph);
    if(cycle)
        cout << "Cycle exists" << endl;
    else
        cout << "No cycle exists" << endl;

    return 0;
}
