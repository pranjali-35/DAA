#include <iostream>
using namespace std;

int main()
{
    int n,x;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *arr = new int(n);
    
    cout << "Enter array elements : ";
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    cout << "Array : ";
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    int key;
    cout << "Enter key element : ";
    cin >> key;
    
    int start = 0, end = n-1, mid;
    while(start <= end){
        mid = start+(end-start)/2;
        if(arr[mid] == key){
            cout << key << " found at position " << mid+1 << endl;
            return 0;
        }else{
            if(key > arr[mid])
                start = mid+1;
            else
                end = mid;
        }
    }cout << "Element not found in the array" << endl;
    return 0;
}
