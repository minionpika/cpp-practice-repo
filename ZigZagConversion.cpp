#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1) return s;

    string sout[numRows], zigzag;
    int x = 0, inc;

    for (int i=0; i<(int)s.size(); i++)
    {
        sout[x] += s[i];
        if (x == 0)
            inc = 1;
        else if ((x+1) % numRows == 0)
            inc = 0;
        if (inc)
            x++;
        else
            x--;
    }
    for (int z=0; z<numRows; z++)
    {

        //cout<<sout[z]<<" ";
        zigzag += sout[z];
    }
    return zigzag;
}

int main()
{
    cout << convert("A", 1) << endl;
}