/*Implement bubble sort and print :
    1. Sorted array
    2. Number of times comparision is done
    3. Number of times swapping is done*/

#include <iostream>
using namespace std;

void BubbleSort(int n, int *arr){
    int compare_count = 0;
    int swap_count = 0;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swap_count++;
            }compare_count++;
        }
    }cout << "Sorted array : ";
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Number of times comparision is done : " << compare_count << endl;
    cout << "Number of times swapping operation is done : " << swap_count << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    BubbleSort(n,arr);
    
    return 0;
}
