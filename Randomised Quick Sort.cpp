/*Implement Randomised Quick sort*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int lb, int ub){
    int index;
    if(lb == 0){
        index = ub;
    }else{
        index = rand()%lb+(ub-lb+1);
    }
    int pivot = v[index];
    int i = lb-1;
    for(int j = lb ; j <= ub-1 ; j++){
        if(v[j] <= pivot){
            i = i + 1;
            swap(v[j],v[i]);
        }
    }swap(v[i+1],v[ub]);
    return i+1;
}

void RandomQuickSort(vector<int> &v, int lb, int ub){
    if(lb < ub){
        int index = partition(v,lb,ub);
        RandomQuickSort(v,lb,index-1);
        RandomQuickSort(v,index+1,ub);
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
    }RandomQuickSort(v,0,n-1);
    display(v);
    
    return 0;
}
