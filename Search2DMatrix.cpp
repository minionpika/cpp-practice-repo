#include<bits/stdc++.h>
using namespace std;

int rowSearch(vector<int> v, int size, int target)
{
    int start=0, end=size-1, mid;
    
    while (start<=end)
    {
        if (v[start]==target)   return start;
        if (v[size-1]<=target)  return size-1;

        mid=(start+end)/2;

        if (v[mid]<target && target<v[mid+1])
            return mid;
        else if (v[mid] == target)
            return mid;
        else if (v[mid]<target)
            start=mid+1;
        else if (v[mid]>target)
            end=mid-1;
    }
    cout << "row error" << endl;
    return -1;
}

bool binSearch(vector<int> v, int size, int target)
{  
    int start=0, end=size-1, mid;
    
    while (start<=end)
    {
        if (v[start]==target)   return true;
        if (v[size-1]==target)  return true;

        mid=(start+end)/2;

        if (v[mid] == target)
            return true;
        else if (v[mid]<target)
            start=mid+1;
        else if (v[mid]>target)
            end=mid-1;
    }
    return false;
}

bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())    // [], [[]]
        return false;

    int rowSize=(int)matrix.size(), colSize=(int)matrix[0].size();

    vector<int> col_0;
    col_0.resize(rowSize); 

    for (int i=0; i<rowSize; i++)
        col_0[i]=matrix[i][0];

    int targetRowIdx = rowSearch(col_0, rowSize, target);

    if (targetRowIdx == -1)
        return false;
    else
        return binSearch(matrix[targetRowIdx], colSize, target);
}

int main()
{
    int a[3][4] = {
                    {-1,3,5,7},
                    {10,11,16,20},
                    {23,30,34,50}
                };

    vector < vector <int> > dVector;

    int n= 3, k = 4;
    dVector.resize(n);
    for(int i = 0 ; i < n ; ++i){
        dVector[i].resize(k);
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<k; j++)
        {
            cout << a[i][j] << " ";;
            //dVector[i].push_back(a[i][j]);
            dVector[i][j] = a[i][j];
        }
        cout << endl;
    }
 
    while(1){
        int target;
        cin >> target;

        bool ans = searchMatrix(dVector, target);
        (ans == 1)? cout << "true" << endl : cout << "false" << endl;
    }
}