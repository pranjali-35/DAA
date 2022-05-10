#include<iostream>
using namespace std;

//function to search the key in array and return the status and no of comparisions
bool linearSearch(int a[],int n, int key,int &no_of_comparisions)
{
    for(int i = 0 ; i < n ; i++) {
      no_of_comparisions++;
      if(key == a[i])
        return true;
    }return false; 
}

int main()
{
    int n,key,T;
    cout << "Enter number of test cases : ";
    cin >> T;
    while(T--){
        cout << "\nEnter array size: ";
        cin >> n;
        int a[n], no_of_comparisions = 0;
        cout << "Enter Array elements : ";
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        cout << "Enter the element to search in array: ";  
        cin >> key; 
        if(linearSearch(a,n,key,no_of_comparisions)) {
            cout << key << " is found" << endl;
            cout << "No of Comparisions = " << no_of_comparisions;
        }else {
            cout << key << " NOT found" << endl;
            cout << "No of Comparisions = " << no_of_comparisions;
        }
    }
    return 0;
}
