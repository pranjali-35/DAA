/*Sort the words in ascending order*/
#include<bits/stdc++.h>
using namespace std;
void sortwords(int n,string str[])
{
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < n-i ; j++){
            if(str[j] > str[j+1])
                swap(str[j],str[j+1]);
        }
    }
}

void display(int n,string str[])
{
    cout  << endl << "Sorted list : " << endl;
    for(int i = 0 ; i < n ; i++)
        cout << str[i] << "\n";
}

int main()
{
    int n;
    cout << "Enter total words you want to enter\n";
    cin >> n;
    string str[n];
    cout << "Enter the words\n";
    for(int i = 0 ; i < n ; i++)
        cin >> str[i];
    sortwords(n,str);
    display(n,str);
}
