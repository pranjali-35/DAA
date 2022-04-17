/*Implement selection sort and print :
    1. Sorted array
    2. Number of times comparision is done
    3. Number of times swapping is done*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &v, int n, int compare_count, int swap_count){
    cout << "Sorted array : ";
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << "Number of comaparisions : " << compare_count << endl;
    cout << "Number of swapping : " << swap_count << endl;
}

void SelectionSort(vector<int> &v, int n){
    int compare_count = 0, swap_count = 0;
    for(int i = 0 ; i < n-1 ; i++){
        int min = i;
        for(int j = i+1 ; j < n ; j++){
            if(v[j] < v[min]){
                compare_count++;
                min = j;
            }
        }swap(v[i],v[min]);
        swap_count++;
    }display(v,n,compare_count,swap_count);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    SelectionSort(v,n);

    return 0;
}
