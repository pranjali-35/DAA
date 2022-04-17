/*Implement Quick sort*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int lb, int ub){
    int x = v[ub];
    int i = lb-1;
    for(int j = lb ; j <= ub-1 ; j++){
        if(v[j] <= x){
            i = i + 1;
            swap(v[j],v[i]);
        }
    }swap(v[i+1],v[ub]);
    return i+1;
}

void QuickSort(vector<int> &v, int n, int lb, int ub){
    if(lb < ub){
        int index = partition(v,lb,ub);
        QuickSort(v,n,lb,index-1);
        QuickSort(v,n,index+1,ub);
    } 
}

void display(vector<int> v){
    int n = v.size();
    for(int i = 0 ; i < n ; i ++){
        cout << v[i] << " ";
    }cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }QuickSort(v,n,0,n-1);
    display(v);
    
    return 0;
}