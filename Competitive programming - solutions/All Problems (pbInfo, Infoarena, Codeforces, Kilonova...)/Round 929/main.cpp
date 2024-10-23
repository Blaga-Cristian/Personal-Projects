#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back

using namespace std;
ifstream fin("keidei.in");
ofstream fout("keidei.out");
//#define cin fin
//#define cout fout
const int N = 10009;
const bool test_cases = true;

int n, m, q;

void solve()
{
    cin >> n >> m >> q;

    cout << "8\n";

    bool b[8] = {1, 1, 1, 1, 1, 1, 1, 1};

    int ans, r, c;
    string shape;

    while(q --)
    {
        cin >> r >> c >> shape;

        if((r + (c + 1) / 2) % 2)
        {
            b[0] &= (shape == "circle");
            b[1] &= (shape == "square");
        }
        else
        {
            b[0] &= (shape == "square");
            b[1] &= (shape == "circle");
        }

        if((r + c / 2) % 2)
        {
            b[2] &= (shape == "circle");
            b[3] &= (shape == "square");
        }
        else
        {
            b[2] &= (shape == "square");
            b[3] &= (shape == "circle");
        }

        if((c + (r + 1) / 2) % 2)
        {
            b[4] &= (shape == "circle");
            b[5] &= (shape == "square");
        }
        else
        {
            b[4] &= (shape == "square");
            b[5] &= (shape == "circle");
        }

        if((c + r / 2) % 2)
        {
            b[6] &= (shape == "circle");
            b[7] &= (shape == "square");
        }
        else
        {
            b[6] &= (shape == "square");
            b[7] &= (shape == "circle");
        }

        ans = 0;
        for(int i = 0; i < 8; ++i)ans += b[i];
        cout << ans << '\n';
    }
}

int main()
{
    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
