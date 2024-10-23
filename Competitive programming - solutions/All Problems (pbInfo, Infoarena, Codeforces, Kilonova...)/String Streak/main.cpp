#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll


using namespace std;
const int N = 1e5 + 9;

int n;
string s;
VI poz[26];

int main()
{
    cin >> s >> n;

    int sz = s.size();
    FOR(i, 0, sz - 1)
        poz[s[i] - 'a'].pb(i);

    FOR(i, 0, 25)
    {
        int st = 0, dr = - 1, cnt = 0;
        int len = poz[i].size();

        while(dr < sz)
        {

        }
    }

    return 0;
}
