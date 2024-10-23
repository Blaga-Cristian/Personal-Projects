#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>

using namespace std;
const int N = 5009;
const ll Mod = 1e9 + 7;

int n, h, a[N];
///dp[i][j] = prob ca 1...i sa aiba cea mai lung streak de pierderi egal cu j

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}

struct mint
{
    ll v;

    mint(ll v = 0) : v(v % Mod) {}

    mint operator + (mint const& oth){return (v + oth.v) % Mod;}
    mint operator - (mint const& oth){return (v - oth.v + Mod) % Mod;}
    mint operator * (mint const& oth){return (v * oth.v) % Mod;}
    mint operator += (mint const& oth){return *this = *this + oth;}
    mint operator -= (mint const& oth){return *this = *this - oth;}
    mint operator *= (mint const& oth){return *this = *this * oth;}
};

int dp[N][N];

int main()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];


    return 0;
}
