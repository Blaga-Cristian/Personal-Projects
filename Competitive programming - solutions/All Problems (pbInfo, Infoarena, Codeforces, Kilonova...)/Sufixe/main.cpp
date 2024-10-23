#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

using namespace std;
const string TASK("sufixe");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 12e5 + 9;

int n, t, cnt[N], pi[N];
char s[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> t;

    cin >> s;

    pi[0] = 0;
    FOR(i, 1, n - 1)
    {
        pi[i] = pi[i - 1];
        while(pi[i] && s[pi[i]] != s[i])
            pi[i] = pi[pi[i] - 1];

        if(s[pi[i]] == s[i])++ pi[i];
    }

    int op, prv = -1;
    FOR(i, 1, t)
    {
        cin >> op;

        if(op == 1)
        {
            cin >> s[n ++];

            pi[n - 1] = pi[n - 2];
            while(pi[n - 1] && s[pi[n - 1]] != s[n - 1])
                pi[n - 1] = pi[pi[n - 1] - 1];

            if(s[pi[n - 1]] == s[n - 1])++ pi[n - 1];

            cnt[n] = cnt[pi[n - 1]];
        }
        else if(op == 2)
        {
            if(prv == n)continue;
            cnt[n] ++;
            prv = n;
        }
        else if(op == 3)cout << cnt[n] << '\n';

//        cout << s << '\n';
    }
    return 0;
}
