#include <bits/stdc++.h>
using namespace std;
#define edge pair<int,int>

int findParent(int x, vector<int> &parent){
    if(parent[x] == x)
        return x;
    else{
        return findParent(parent[x],parent);
    }
}

void printMST(vector<pair<int,edge>> &MST){
    //cout << "In print";
    int n = MST.size();
    cout << "Edge : Weight" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << MST[i].second.first << " " << MST[i].second.second << "     " << MST[i].first;
    }
}

void kruskals(vector<pair<int,edge>> &Graph, int n, vector<pair<int,edge>> &MST){
    //cout << "in kruskals 1" << endl;
    
    //parent vector
    vector<int> parent(n);
    
    //sort vector in non decreaing order of weight
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }sort(Graph.begin(),Graph.end());
    
    //cout << "kruskals sorted " << endl;
    
    //iterate edges in increasing order and add them in MST if it does not form a cycle
    for(int i = 0 ; i < Graph.size() ; i++){
        //cout << "in for" << endl;
        pair<int,edge> currentEdge = Graph[i];
        int uParent = findParent(currentEdge.second.first,parent);
        int vParent = findParent(currentEdge.second.second,parent);
        if(uParent != vParent){
            //cout << "in if " << endl;
            MST.push_back(Graph[i]);
            parent[uParent] = vParent;
        }//cout << "out if" << endl;
    }//cout << "in kruskals 2" << endl;
    
}

int main()
{
    int n,e,u,v,w;
    vector<pair<int,edge>> Graph;
    vector<pair<int,edge>> MST;
    
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> e;
    
    for(int i = 0 ; i < e ; i++){
        cout << "Enter the weight of the edge : ";
        cin >> w;
        cout << "Enter the edge nodes : ";
        cin >> u >> v;
        
        Graph.push_back({w,{u,v}});
    }kruskals(Graph,n,MST);
    printMST(MST);

    return 0;
}
