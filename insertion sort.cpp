/*Implement insertion sort and print :
    1. Sorted array
    2. Total number of comparisions
    3. Total number of write operations.*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> v, int n, int compare_count, int write_count){
    cout << "Sorted array : ";
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << "Number of comaparisions : " << compare_count << endl;
    cout << "Number of swapping : " << write_count << endl;
}

void InsertionSort(vector<int> v, int n){
    int compare_count = 0, write_count = 0;
    for(int i = 1 ; i < n ; i++){
        int key = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > key){
            write_count++;
            compare_count++;
            v[j+1] = v[j];
            j = j-1;
        }v[j+1] = key;
        write_count++;
    }
    display(v,n,compare_count,write_count);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    InsertionSort(v,n);

    return 0;
}
