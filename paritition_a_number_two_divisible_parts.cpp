#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

string stringPartition(string s, int x, int y)
{
    int n = s.size();

    string a = "";
    string b = "";
    vector<pair<string, string>> v;
    for (int i = n - 1; i >= 1; i--)
    {
        b += s[i];
        s.pop_back();
        a = s;
        reverse(b.begin(), b.end());
        v.emplace_back(a, b);
        reverse(b.begin(), b.end());
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        int g = stoi(v[i].first);
        int h = stoi(v[i].second);
        if (g % x == 0 and h % y == 0)
        {
            return (v[i].first + " " + v[i].second);
        }
    }

    return "-1";
}