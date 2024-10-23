#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vb vector<bool>
#define vvb vector<vb>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

map<string, string> mp;

const string TASK("level7_5");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
//#define cout fout


//string check(string str)
//{
//    string v1, v2 = str;
//
//    cout << str << '\n';
//
//    while(v2.size() != 1)
//    {
//        swap(v2, v1);
//        v2.clear();
//
//        for(int i = 0; i + 1 < v1.size(); i += 2)
//            v2 += mp[{v1[i], v1[i + 1]}];
//
//        cout << v2 << '\n';
//    }
//
//    return v2;
//}

int p2;

const int N = 5000, LG = 32;

map<string, bool> tst[LG][N];
bool check(string str)
{
    FOR(i, 0, LG - 1)FOR(j, 0, N - 1)tst[i][j].clear();

    FOR(i, 0, (int)str.size() - 1)
    {
        if(str[i] == 'S')tst[0][i]["S"] = true;
        if(str[i] == 'L')tst[0][i]["L"] = true;
        if(str[i] == 'P')tst[0][i]["P"] = true;
        if(str[i] == 'Y')tst[0][i]["Y"] = true;
        if(str[i] == 'R')tst[0][i]["R"] = true;
        if(str[i] == 'Z')
        {
            tst[0][i]["Y"] = true;
            tst[0][i]["S"] = true;
            tst[0][i]["L"] = true;
            tst[0][i]["P"] = true;
            tst[0][i]["R"] = true;
        }
    }

    for(int k = 1; k <= p2; ++k)
        for(int i = 0; i < str.size(); i += (1 << k))
            for(auto [s1, _] : tst[k - 1][i])
                for(auto [s2, _] : tst[k - 1][i + (1 << (k - 1))])
                    tst[k][i][mp[s1 + s2]] = true;

    cout << "You can get ";
    for(auto [e, _] : tst[p2][0])
        cout << e << ' ';
    cout << '\n';
}

set<set<string>> dp[LG][N];
set<string> operator + (set<string> const& a, set<string> const& b)
{
    set<string> res;
    for(auto e1 : a)
        for(auto e2 : b)
            res.insert(mp[e1 + e2]);
    return res;
}

string res, str;

void Dfs(int pw, int pos, set<string> tar)
{
    if(pw == 1)
    {
        for(auto s1 : dp[pw - 1][pos])
            for(auto s2 : dp[pw - 1][pos + (1 << (pw - 1))])
                if(s1 + s2 == tar)
                {
                    if(str[pos] == 'Z')res += 'Z';
                    else res += *s1.begin();

                    if(str[pos + 1] == 'Z')res += 'Z';
                    else res += *s2.begin();

                    return;
                }
    }

    for(auto s1 : dp[pw - 1][pos])
        for(auto s2 : dp[pw - 1][pos + (1 << (pw - 1))])
            if(s1 + s2 == tar)
            {
                Dfs(pw - 1, pos, s1);
                Dfs(pw - 1, pos + (1 << (pw - 1)), s2);
                return;
            }

}

void solve()
{
    cin >> str;

    res.clear();

    FOR(i, 0, p2)FOR(j, 0, (int)str.size())dp[i][j].clear();

    FOR(i, 0, (int)str.size() - 1)
    {
        if(str[i] == 'X')
        {
            dp[0][i].insert({"S"});
            dp[0][i].insert({"L"});
            dp[0][i].insert({"P"});
            dp[0][i].insert({"Y"});
            dp[0][i].insert({"R"});
        }
        if(str[i] == 'Z')dp[0][i].insert({"S", "L", "P", "Y", "R"});
        if(str[i] == 'S')dp[0][i].insert({"S"});
        if(str[i] == 'L')dp[0][i].insert({"L"});
        if(str[i] == 'P')dp[0][i].insert({"P"});
        if(str[i] == 'Y')dp[0][i].insert({"Y"});
        if(str[i] == 'R')dp[0][i].insert({"R"});
    }

    for(int k = 1; k <= p2; ++k)
        for(int i = 0; i < str.size(); i += (1 << k))
            for(auto s1 : dp[k - 1][i])
                for(auto s2 : dp[k - 1][i + (1 << (k - 1))])
                    dp[k][i].insert(s1 + s2);


    Dfs(p2, 0, {"S"});
    fout << res << '\n';
    check(res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    mp["PS"] = "S";
    mp["PR"] = "P";
    mp["PP"] = "P";
    mp["PY"] = "P";
    mp["PL"] = "L";

    mp["SP"] = "S";
    mp["SR"] = "R";
    mp["SS"] = "S";
    mp["SY"] = "Y";
    mp["SL"] = "S";

    mp["RR"] = "R";
    mp["RP"] = "P";
    mp["RS"] = "R";
    mp["RY"] = "Y";
    mp["RL"] = "R";

    mp["YR"] = "Y";
    mp["YP"] = "P";
    mp["YS"] = "Y";
    mp["YY"] = "Y";
    mp["YL"] = "L";

    mp["LR"] = "R";
    mp["LP"] = "L";
    mp["LS"] = "S";
    mp["LY"] = "L";
    mp["LL"] = "L";

//    mp["ZR"] = mp["RZ"] = "Z";
//    mp["ZS"] = mp["SZ"] = "Z";
//    mp["ZL"] = mp["LZ"] = "R";
//    mp["ZP"] = mp["PZ"] = "P";
//    mp["ZY"] = mp["YZ"] = "Y";
//    mp["ZZ"] = "Z";

    int t = 1;
    cin >> t >> p2;
    p2 = log2(p2);
    while(t --)
        solve();
    return 0;
}
