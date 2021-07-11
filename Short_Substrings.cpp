#include<bits/stdc++.h>
using namespace std;

string secretString(string x) {
    string secStr = "";
    secStr += x[0];

    for (int i=1; i<=(int)x.size()-1; i+=2)
        secStr += x[i];
    return secStr;
}

int main() {
    int test;
    string x = "";
    cin >> test;

    for (int t=0; t<test; t++) {
        cin >> x;
        if ((int)x.size() > 2)
            x = secretString(x);
        cout << x << endl;
    }
}