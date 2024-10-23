#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VB vector<bool>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const int N = 2e5 + 9;

int n, sp[N];
string s[N];
unordered_map<int, int> dp[11][11];
ll ans;

void get_sp(string str)
{
    sp[0] = str[0] - '0';
    FOR(i, 1, str.size())
        sp[i] = sp[i - 1] + str[i] - '0';
}

int main()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> s[i];
        int sz = s[i].size();
        get_sp(s[i]);

        for(int len = 2; len <= 10; len += 2)
        {
            if(sz > len)continue;

            int point = len / 2;
            if(sz <= point)dp[len][sz][sp[sz - 1]]++;
            else dp[len][sz][sp[point - 1] - (sp[sz - 1] - sp[point - 1])] ++;
        }
    }

    FOR(i, 1, n)
    {
        int sz = s[i].size();
        get_sp(s[i]);

        for(int len = 2; len <= 10; len += 2)
        {
            if(sz > len)continue;

            int point = len / 2;
            if(sz <= point)ans += dp[len][len - sz][sp[sz - 1]];
            else ans += dp[len][len - sz][(sp[sz - 1] - sp[sz - point - 1]) - sp[sz - point - 1]];
        }
    }

    cout << ans;
    return 0;
}
