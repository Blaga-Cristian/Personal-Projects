#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back


using namespace std;
const string TASK("ssm");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 6e6 + 9;

int n, a[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    int ans = a[1], cur = a[1], ind = 1;
    pii ans_i{1, 1};

    for(int i = 2; i <= n; ++i)
    {
        if(cur + a[i] < a[i])ind = i;
        cur = max(cur + a[i], a[i]);
        if(cur > ans)
        {
            ans = cur;
            ans_i = {ind, i};
        }
    }

    cout << ans << ' ' << ans_i.ff << ' ' << ans_i.ss << '\n';
    return 0;
}