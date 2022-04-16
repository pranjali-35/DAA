/*Implement merge sort*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> v, int n){
    for(int i = 0 ; i < n ; i++){
        cout << v[i] << " ";
    }cout << endl;
}

void merge(int n, vector<int> &v, int lb, int mid, int ub){
    vector<int> b(n);
    int i = lb, j = mid+1, k = lb;
    while(i <= mid && j <= ub){
        if(v[i] <= v[j]){
            b[k] = v[i];
            i++;
        }else{
            b[k] = v[j];
            j++;
        }k++;
    }while(j <= ub){
            b[k] = v[j];
            j++;
            k++;
    }while(i <= mid){
            b[k] = v[i];
            i++;
            k++;
    }
    
    //copying elements from sorted vector to orginal vector
    for(int k = lb ; k <= ub ; k++){
        v[k] = b[k];
    }
    
}

void mergeSort(int n,vector<int> &v, int lb, int ub){
    if(lb < ub){
        int mid = (lb+ub)/2;
        mergeSort(n,v, lb, mid);
        mergeSort(n,v, mid+1, ub);
        merge(n,v, lb, mid, ub);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }mergeSort(n,v,0,n-1);
    display(v,n);

    return 0;
}
