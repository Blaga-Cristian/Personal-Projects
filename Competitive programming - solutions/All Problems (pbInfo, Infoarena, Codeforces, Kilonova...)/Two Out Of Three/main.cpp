#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const bool has_testcases = true;
const int N = 1e5 + 9;

int n, a[N], b[N];
int nr[3], cntnr[3];
unordered_map<int, int> mp;


void solve_testcase()
{
    cin >> n;
    mp.clear();

    FOR(i, 1, n)
    {
        cin >> a[i];
        mp[a[i]] ++;
    }


    FOR(i, 1, n)
        b[i] = 1;

    int cnt2 = 0;
    nr[1] = nr[2] = 0;
    for(auto i : mp)
        if(i.second >= 2)
        {
            nr[++ cnt2] = i.first;
            if(cnt2 == 2)break;
        }

    if(cnt2 < 2)
    {
        cout << "-1\n";
        return;
    }

    cntnr[1] = cntnr[2] = 0;
    FOR(i, 1, n)
    {
        if(a[i] == nr[1])
        {
            cntnr[1]++;
            if(cntnr[1] == 2)
                b[i] = 2;
        }
        if(a[i] == nr[2])
        {
            cntnr[2]++;
            if(cntnr[2] == 2)
                b[i] = 3;
        }
    }

    FOR(i, 1, n)
        cout << b[i] << ' ';
    cout << '\n';
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_testcases) cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
