/*Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted
array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform
a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): Jump Search
*/

//jump search

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int *arr = new int(n);
    
    for(int i = 0; i < n ; i++)
        cin >> arr[i];
    

    int key;
    cout << "Enter key element : ";
    cin >> key;
        
    if(key < arr[0] || key > arr[n-1]){
        cout << "Element does not exist" << endl;
        exit(0);
    }if(key == arr[n-1]){
        cout << "Element found at : " << n-1 << endl;
        exit(0);
    }
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    while(arr[i] < key){
        i1 = i2;
        i++;
        i2 = i;
    }
    //cout << "i = " << arr[i] << " i1 = " << arr[i1] << " i2 = " << arr[i2] << endl;
    
    for(int j = i1 ; j <= i2 ; j++){
        if(arr[j] == key){
            cout << "Element found at index : " << j << endl;
            exit(0);
        }
    }cout << "Element not found" << endl;
   
    return 0;
}
