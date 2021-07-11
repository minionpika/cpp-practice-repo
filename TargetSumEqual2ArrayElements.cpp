#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> visited;

    int arr[] = {5, 7, 1, 2, 8, 4, 3};
    int tsum = 10;
    int size = (int)sizeof(arr)/sizeof(int);
    
    for (int i=0; i<size; i++)
    {
        if (visited.find(tsum - arr[i]) == visited.end())
            visited.insert(arr[i]);
        else
            cout << "got it" << endl;
    }

/*    unordered_set<int> :: iterator it;
    for (it=duplic.begin(); it!=duplic.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl;*/

}