#include <bits/stdc++.h>
#define int long long
#define ll int
#define pii pair<ll, ll>
#define ff first
#define ss second
#define vi vector<ll>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define vvvpi vector<vvpi>
#define vvi vector<vi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const int N = 1e5 + 9, Inf = 1e9, ITERATIONS = 30;

const string TASK("level7_1");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//ofstream fout("output");
#define cin fin
#define cout fout

ll n, hh, m, maxp, maxe, maxc, a[N], sp[N];

struct info
{
    ll id, power, l, r;
};
vector<vector<info>> h, h_c;
vvvpi ans;

ll C_L = INT_MAX;
ll C_P = 87;
ll C_M = 36;

ll F(ll len)
{
    return C_L * ((double)1 / len);
}
ll G(ll power)
{
    return C_P * power;
}
ll H(ll mean)
{
    return C_M * mean;
}

ll get_score(info t)
{
    return F(t.r - t.l + 1) +
    G(t.power) +
    H((sp[t.r] - sp[t.l - 1]) / (t.r - t.l + 1));
}

///CEL CU SCORUL MAI MARE ESTE ALES
bool cmp(pii a, pii b)
{
    return get_score(h_c[a.ff][a.ss]) > get_score(h_c[b.ff][b.ss]);
}

bool cmp1(pii a, pii b)
{
    return get_score(h[a.ff][a.ss]) > get_score(h[b.ff][b.ss]);
}

mt19937 rng;
uniform_int_distribution<> distrib(-100, 100);

void Train_AI()
{
    vpi v;
    FOR(i, 1, n)v.pb({a[i], i});
    sort(v.begin(), v.end());

    ll best = LLONG_MAX >> 2;
    vi coef;
    vi cons(n + 1, 0);

    FOR(_, 1, ITERATIONS)
    {
        C_L = distrib(rng);
        C_P = distrib(rng);
        C_M = distrib(rng);
        h_c = h;
        FOR(i, 1, n)cons[i] = 0;

        ll cost = 0;
        FOR(i, 1, hh)
        {
            for(auto [c, ind] : v)
            {
                vpi av;
                FOR(j, 1, (int)h_c[i].size() - 1)
                    if(h_c[i][j].l <= ind && ind <= h_c[i][j].r &&
                        h_c[i][j].power > 0)
                            av.pb({i, j});

                sort(av.begin(), av.end(), cmp);

                int cur = maxp;
                for(int i = 0; i < min(maxc, (ll)av.size()) && cur; ++i)
                    if(h_c[av[i].ff][av[i].ss].power <= cur)
                    {
                        cost -= cons[ind] * c;
                        cons[ind] += h_c[av[i].ff][av[i].ss].power;
                        cost += cons[ind] * c;
                        cur -= h_c[av[i].ff][av[i].ss].power;
                        h_c[av[i].ff][av[i].ss].power = 0;
                    }
                    else
                    {
                        cost -= cons[ind] * c;
                        cons[ind] += cur;
                        cost += cons[ind] * c;
                        h_c[av[i].ff][av[i].ss].power -= cur;
                        cur = 0;
                    }
            }
        }


        if(cost < best)
        {
            best = cost;
            coef = {C_L, C_P, C_M};

            for(auto e : coef)cout << e << ' ';
            cout << cost << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> maxp >> maxe >> maxc;

    cin >> n;
    FOR(i, 1, n)cin >> a[i];
    FOR(i, 1, n)sp[i] = sp[i - 1] + a[i];

    cin >> hh;
    h.resize(hh + 1);
    ans.resize(hh + 1);
    FOR(i, 1, hh)
    {
        cin >> m;
        h[i].resize(m + 1);
        ans[i].resize(m + 1);
        FOR(j, 1, m)
        {
            cin >> h[i][j].id >> h[i][j].power >> h[i][j].l >> h[i][j].r;
            h[i][j].l ++, h[i][j].r ++;
        }
    }

//    Train_AI();

    vpi v;
    FOR(i, 1, n)v.pb({a[i], i});
    sort(v.begin(), v.end());

    vi cons(n + 1, 0);
    ll cost = 0;

    FOR(i, 1, hh)
    {
        for(auto [c, ind] : v)
        {
            vpi av;
            FOR(j, 1, (int)h[i].size() - 1)
                if(h[i][j].l <= ind && ind <= h[i][j].r &&
                    h[i][j].power > 0)
                        av.pb({i, j});

            sort(av.begin(), av.end(), cmp1);

            int cur = maxp;
            for(int j = 0; j < min(maxc, (ll)av.size()) && cur; ++j)
            {
//                cout << "FIXING " << av[j].ff << ' ' << av[j].ss << '\n';
                if(h[av[j].ff][av[j].ss].power <= cur)
                {
                    cost -= ceil(((double)1.0 + (double)cons[ind] / maxp) * c);
                    cons[ind] += h[av[j].ff][av[j].ss].power;
                    cost += ceil(((double)1.0 + (double)cons[ind] / maxp) * c);

                    ans[av[j].ff][av[j].ss].pb({ind, h[av[j].ff][av[j].ss].power});
                    cur -= h[av[j].ff][av[j].ss].power;
                    h[av[j].ff][av[j].ss].power = 0;
                }
                else
                {
                    cost -= ceil(((double)1.0 + (double)cons[ind] / maxp) * c);
                    cons[ind] += cur;
                    cost += ceil(((double)1.0 + (double)cons[ind] / maxp) * c);

                    ans[av[j].ff][av[j].ss].pb({ind, cur});
                    h[av[j].ff][av[j].ss].power -= cur;
                    cur = 0;
                }
            }
        }
    }

    cout << hh << '\n';
    FOR(i, 1, hh)
    {
        cout << i << '\n';

        cout << (int)h[i].size() - 1 << '\n';
        FOR(j, 1, (int)h[i].size() - 1)
        {
            cout << j << ' ';
            int total = 0;
            sort(ans[i][j].begin(), ans[i][j].end());
            for(auto e : ans[i][j])cout << e.ff - 1 << ' ' << e.ss << ' ', total += e.ss;
//            cout << "TOTAL IS " << total;
            cout << '\n';
        }
    }

    FOR(i, 1, n)cons[i] = 0;
    cost = 0;
    FOR(i, 1, hh)
        FOR(j, 1, (int)h[i].size() - 1)
            for(auto e : ans[i][j])
                cons[e.ff] += e.ss;

    FOR(i, 1, n)cost += ceil((1.0 + ((double)cons[i]) / maxp) * a[i]);

//    cout << cost << '\n';
    return 0;
}
