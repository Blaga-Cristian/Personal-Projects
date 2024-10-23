#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back


using namespace std;
const string TASK("sdo");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 3e6 + 9;

int n, k, a[N];


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    nth_element(a + 1, a + k, a + n + 1);

    cout << a[k] << '\n';
    return 0;
}