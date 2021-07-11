#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double res;

    if (n==0)
        return 1;
    if(x==0) return 0;
    
    else if (n%2==0)
    {
        res = myPow(x, n/2);
        return res * res;
    }
    else
    {
        if (n<0)
            return (1.0/x) * myPow(x, n+1);
        else
            return x * myPow(x, n-1);
    }
    
}

int main()
{
    double x;
    int n;
    cin>>x>>n;

    cout<<myPow(x,n)<<endl;
}