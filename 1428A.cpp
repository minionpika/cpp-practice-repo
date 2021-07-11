#include<bits/stdc++.h>
using namespace std;

int main()
{
    int testCase; cin >> testCase;
    int x, y, x1, y1, xLength, yLength;

    for (int t=1; t<=testCase; t++)
    {
        cin>>x>>y>>x1>>y1;
        xLength = abs(x-x1);
        yLength = abs(y-y1);

        if (xLength == 0 || yLength == 0)   // either x=x1 or y=y1, or both
        {
            cout << xLength+yLength<<endl;
        }
        else    // x!=x1 && y!=y1
        {
            cout << xLength+yLength+2<<endl;
        }
    }
}