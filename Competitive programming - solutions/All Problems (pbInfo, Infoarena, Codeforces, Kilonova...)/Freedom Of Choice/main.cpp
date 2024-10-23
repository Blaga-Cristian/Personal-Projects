#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define VP vector<PI>
#define VVP vector<VP>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define VL vector<ll>
#define VVL vector<VL>
#define int long long
#define pb push_back
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


using namespace std;
const bool has_testcases = true;
const int N = 1e5 + 9;


void solve() {
  int m;
  cin >> m;
  vector<int> n(m), l(m), r(m);
  vector<vector<int>> a(m);
  vector<vector<int>> c(m);
  vector<int> sumc(m);
  int suml = 0, sumr = 0, sumn = 0;
  for (int i = 0; i < m; i++) {
    cin >> n[i] >> l[i] >> r[i];
    sumn += n[i];
    suml += l[i];
    sumr += r[i];
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
    }
    c[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> c[i][j];
      sumc[i] += c[i][j];
    }
  }

  if (sumr - suml > sumn) {
    cout << "0\n";
    return;
  }

  map<int, int> sumr_a;
  map<int, vector<pair<int, int>>> indexes;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n[i]; j++) {
      sumr_a[a[i][j]] += r[i];
      indexes[a[i][j]].pb({i, j});
    }
  }

  int ans = (int) 2e18;
  for (int len = suml; len <= sumr; len++) {
    int xsize = 0, must_len = 0;
    xsize += sumr - sumr_a[len];
    for (auto &[i, pos] : indexes[len]) {
      int cnt_not_len = sumc[i] - c[i][pos];
      if (cnt_not_len < l[i]) {
        xsize += l[i];
        must_len += l[i] - cnt_not_len;
      } else {
        xsize += min(cnt_not_len, r[i]);
      }
    }
    ans = min(ans, must_len + max(0LL, len - xsize));
  }
  cout << ans << '\n';
}



void solve_testcase()
{
    ll m;
    cin >> m;
    VL n(m), l(m), r(m);
    VVL a(m);
    VVL c(m);
    VL sumc(m);

    ll suml = 0, sumr = 0, sumn = 0;
    FOR(i, 0, m - 1)
    {
        cin >> n[i] >> l[i] >> r[i];
        sumn += n[i];
        suml += l[i];
        sumr += r[i];

        a[i].resize(n[i]);
        FOR(j, 0, n[i] - 1)
            cin >> a[i][j];

        c[i].resize(n[i]);
        FOR(j, 0, n[i] - 1)
        {
            cin >> c[i][j];
            sumc[i] += c[i][j];
        }
    }

    if(sumr - suml > sumn)
    {
        cout << "0\n";
        return;
    }

    map<ll, ll> sumr_a;
    map<ll, VP> indexes;
    FOR(i, 0, m - 1)
        FOR(j, 0, n[i] - 1)
        {
            sumr_a[a[i][j]] += r[i];
            indexes[a[i][j]].pb({i, j});
        }

    ll ans = LLONG_MAX;
    FOR(len, suml, sumr)
    {
        ll xsize = 0, must_len = 0;
        xsize = sumr - sumr_a[len];

        for(auto [i, poz] : indexes[len])
        {
            ll cnt_not_len = sumc[i] - c[i][poz];

            if(cnt_not_len < l[i])
            {
                xsize += l[i];
                must_len += l[i] - cnt_not_len;
            }
            else
                xsize += min(cnt_not_len, r[i]);
        }

        ans = min(ans, must_len + max(0LL, len - xsize));
    }

    cout << ans << '\n';
}

signed main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_testcases) cin >> t;
    while(t --)
        solve();
}
