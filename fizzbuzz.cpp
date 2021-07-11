#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int divBy3(int n)
{
    int tot=0;
    string s = std::to_string(n);
    for (int i=0; i<(int)s.size(); i++)
    {
        tot += s[i] - '0';
    }
    cout << tot <<"-------------------------"<< s << endl;
    if (tot%3==0)
        return 1;
    else
        return 0;
}

int divBy5(int n)
{
    string s = std::to_string(n);
    int _size = (int)s.size();
    int lastDigit = s[_size-1] - '0';

    if (lastDigit==0 || lastDigit==5)
        return 1;
    else
        return 0;
}

void fizzBuzz(int n) {

    int div3, div5;

    for (int i=1; i<=n; i++) {
        div3 = divBy3(i);
        div5 = divBy5(i);

        if (div3 && div5)
            cout << "FizzBuzz" << endl;
        else if (div3)
            cout << "Fizz" << endl;
        else if (div5)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    fizzBuzz(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
