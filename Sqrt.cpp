#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    unsigned int start=0,end=x;
    long long int mid, mid_sqre;
    
    if (x<=1) return x;
    while(start<end)
    {
        mid=(start+end) / 2;
        if (start == mid || end == mid) return mid;
        mid_sqre = mid*mid;
        if (mid_sqre>x) end=mid;
        else if (mid_sqre<x) start=mid;
        else if (mid_sqre == x) return mid;
    }
    return 0;
}

int main()
{
    int x; cin>>x;
    cout<<mySqrt(x)<<endl;
}