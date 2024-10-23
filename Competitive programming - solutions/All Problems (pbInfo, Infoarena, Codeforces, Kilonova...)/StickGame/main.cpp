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
const int N = 1e6 + 9, K = 109;

int n, k, m[K];
bool dp[N];
///dp[i] = 0, is i is losing, and dp[i] = 1, if i is winning

int main()
{
    dp[0] = 0;

    cin >> n >> k;
    FOR(i, 1, k)cin >> m[i];

    FOR(i, 1, n)
        FOR(j, 1, k)
            if(i >= m[j] && dp[i - m[j]] == 0)
                dp[i] = 1;


    FOR(i, 1, n)
        cout << (dp[i] == 1 ? "W" : "L");
    return 0;
}
