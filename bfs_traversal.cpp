#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&graph,int s, int n){
    vector<bool> visited(n,false);
    visited[s] = true;
    
    list<int> queue;
    queue.push_back(s);
            
    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
                
        for(auto adjacent:graph[s]){
            if(!visited[adjacent]){
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
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
    cout << "BFS with source " << source << " : ";
    BFS(graph,source, n);
    

    return 0;
}
