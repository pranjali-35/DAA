/*Implement count sort*/

#include <bits/stdc++.h>
using namespace std;

void CountSort(vector<int> &v, int k){
    int n = v.size();
    vector<int> count(k+1);
    vector<int> b(n);
    for(int i = 0 ; i < n ; i++){
        count[v[i]]++;
    }for(int i = 1 ; i <= k ; i++){
        count[i] = count[i] + count[i-1];
    }for(int i = n-1 ; i >= 0 ; i--){
        b[--count[v[i]]] = v[i];
    }for(int i = 0 ; i < n ; i++){
        v[i] = b[i];
    }
}

void display(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i < n ; i++){
        cout << v[i] << " ";
    }cout << endl;
}

int max_element(vector<int> &v){
    int n = v.size();
    int max = v[0];
    for(int i = 0 ; i < n ; i++){
        if(v[i] > max){
            max = v[i];
        }
    }return max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    int max = max_element(v);
    CountSort(v,max);
    display(v);

    return 0;
}
