#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> uniq;
    unordered_set<int> duplic;

    int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
    int size = (int)sizeof(arr)/sizeof(int);
    for (int i=0; i<size; i++)
    {
        if (uniq.find(arr[i]) == uniq.end())
            uniq.insert(arr[i]);
        else
            duplic.insert(arr[i]);
    }

    unordered_set<int> :: iterator it;
    for (it=duplic.begin(); it!=duplic.end(); it++)
    {
        cout << *it << " " ;
    }
    cout << endl;

}