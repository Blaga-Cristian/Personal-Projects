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
const int N = 1e5 + 9;

const string TASK("level6_5");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
//#define cout fout


int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

///PRIO stanga, jos, sus, dreapta
int dx1[] = {0, 1, -1, 0}, dy1[] = {-1, 0, 0, 1};
///PRIO sus, dreapta, stanga, jos
int dx2[] = {-1, 0, 0, 1}, dy2[] = {0, 1, -1, 0};

char res[] = {'W', 'D', 'S', 'A'};

map<char, int> rdx = {{'W', -1}, {'D', 0}, {'S', 1}, {'A', 0}};
map<char, int> rdy = {{'W', 0}, {'D', 1}, {'S', 0}, {'A', -1}};

int n, m;

pii t;
int cnt = 0;
bool found = false;
vvb viz;

int st, dr, s, j;
bool inmat(int x, int y)
{
    return (x >= s && x <= j && y >= st && y <= dr);
}

vi r;
pii lst;
void Dfs2(int x, int y, bool tip = false)
{
    viz[x][y] = true;
    lst = {x, y};
    cnt ++;

    for(int k = 0; k < 4; ++k)
    {
        int nx, ny;
        if(tip)nx = x + dx1[k], ny = y + dy1[k];
        else nx = x + dx[k], ny = y + dy[k];


        if(inmat(nx, ny) && (nx != t.ff || ny != t.ss) && !viz[nx][ny])
        {
            if(!tip)r.pb(k);
            else
            {
                if(k == 0)r.pb(3);
                else if(k == 1)r.pb(2);
                else if(k == 2)r.pb(0);
                else r.pb(1);
            }
            Dfs2(nx, ny, tip);
            return;
        }
    }
}

vi path;
bool inmat1(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}
void Dfs(int x, int y, int tip = 0)
{
    viz[x][y] = true;
    for(int k = 0; k < 4; ++k)
    {
        int nx, ny;
        if(tip == 0)nx = x + dx[k], ny = y + dy[k];
        else if(tip == 1)nx = x + dx1[k], ny = y + dy1[k];
        else if(tip == 2)nx = x + dx2[k], ny = y + dy2[k];

        if(inmat1(nx, ny) && !viz[nx][ny] && (nx != t.ff || ny != t.ss))
        {
            if(tip == 0)path.pb(k);
            else if(tip == 1)
            {
                if(k == 0)path.pb(3);
                else if(k == 1)path.pb(2);
                else if(k == 2)path.pb(0);
                else path.pb(1);
            }
            else if(tip == 2)
            {
                if(k == 0)path.pb(0);
                else if(k == 1)path.pb(1);
                else if(k == 2)path.pb(3);
                else path.pb(2);
            }

            Dfs(nx, ny, tip);
            return;
        }
    }
}

bool valid(vector<int> const& pth)
{
    vvb v(n + 1, vb(m + 1));

    FOR(x, 1, n)
        FOR(y, 1, m)
        {
            FOR(i, 1, n)FOR(j, 1, m)v[i][j] = false;

            pii cell = {x, y};
            v[x][y] = true;
            int cnt = 1;

            for(auto e : pth)
            {
                cell.ff += dx[e], cell.ss += dy[e];

                if(!inmat1(cell.ff, cell.ss) || v[cell.ff][cell.ss] || cell == t)break;

                v[cell.ff][cell.ss] = true;
                cnt ++;
            }

            if(cell != t && cnt == n * m - 1 && abs(x - cell.ff) + abs(y - cell.ss) == 1)return true;
        }

    return false;
}



vi solve()
{
    cnt = 0;
    found = false;
    path.clear();
    r.clear();
    lst = {0, 0};
    s = j = st = dr = 0;

    ///is on the edge

    if(n % 2 == 0)
    {
        vi path;
        path.pb(1);
        FOR(i, 1, n)
        {
            if(i % 2 == 1)
            {
                FOR(j, 2, m - 1)path.pb(1);
                path.pb(2);
            }
            else
            {
                FOR(j, 2, m - 1)path.pb(3);
                path.pb(2);
            }
        }
        path.pop_back();

        path.pb(3);
        FOR(i, 2, n - 1)path.pb(0);

        if(t.ff == 1 && t.ss == 1)
        {
            path.erase(path.begin());
            return path;
        }

        int x = 1, y = 1, p = -1;
        for(int i = 0; i < path.size(); ++i)
        {
            if(path[i] == 0)x --;
            if(path[i] == 1)y ++;
            if(path[i] == 2)x ++;
            if(path[i] == 3)y --;

            if(x == t.ff && y == t.ss)p = i;
        }


        vi ans;
        for(int i = p + 2; i < path.size(); ++i)
            ans.pb(path[i]);
        ans.pb(0);
        for(int i = 0; i < p; ++i)
            ans.pb(path[i]);

        return ans;
    }
//    else if(t.ff == 1 || t.ff == n)
    else if(false)
    {
        if(t.ff == 1)
        {
            st = 1, dr = m;
            s = 1, j = 2;

            viz = vvb(n + 1, vb(m + 1));
            r.clear();
            cnt = 0;
            Dfs2(2, 1, true);

            if(cnt == 2 * m - 1)
            {
                vi ans;
                for(auto it = r.rbegin(); it != r.rend(); ++it)
                    ans.pb((*it + 2) % 4);

                path.clear();
                Dfs(2, 1);
                for(auto e : path)ans.pb(e);

                return ans;
            }
            else
            {
                viz = vvb(n + 1, vb(m + 1));
                r.clear();
                cnt = 0;
                Dfs2(2, m, false);

                vi ans;
                for(auto it = r.rbegin(); it != r.rend(); ++it)
                    ans.pb((*it + 2) % 4);

                path.clear();
                Dfs(2, m);
                for(auto e : path)ans.pb(e);

                return ans;
            }
        }
        else if(t.ff == n)
        {
            st = 1, dr = m;
            s = n - 1, j = n;

            viz = vvb(n + 1, vb(m + 1));
            r.clear();
            cnt = 0;
            Dfs2(n - 1, 1, true);

            if(cnt == 2 * m - 1)
            {
                vi ans;
                for(auto it = r.rbegin(); it != r.rend(); ++it)
                    ans.pb((*it + 2) % 4);

                path.clear();
                Dfs(n - 1, 1);
                for(auto e : path)ans.pb(e);

                return ans;
            }
            else
            {
                viz = vvb(n + 1, vb(m + 1));
                r.clear();
                cnt = 0;
                Dfs2(n - 1, m, false);

                vi ans;
                for(auto it = r.rbegin(); it != r.rend(); ++it)
                    ans.pb((*it + 2) % 4);

                path.clear();
                Dfs(n - 1, m);
                for(auto e : path)ans.pb(e);

                return ans;
            }
        }

        return {};
    }
    else
    {
        st = 1, dr = m;
        s = t.ff - 1, j = t.ff;

        viz = vvb(n + 1, vb(m + 1));
        vi ans;

        r.clear();
        cnt = 0;
        Dfs2(t.ff - 1, 1, true);

        if(cnt == 2 * m - 1 && lst.ff == t.ff)
        {
            path.clear();
            Dfs(t.ff - 1, 1);
            for(auto e = path.rbegin(); e != path.rend(); ++e)
                ans.pb((*e + 2) % 4);

            for(auto e : r)ans.pb(e);

            path.clear();
            Dfs(lst.ff, lst.ss);
            for(auto e : path)ans.pb(e);

            return ans;
        }
        else
        {
            FOR(i, 1, n)FOR(j, 1, m)viz[i][j] = false;

            r.clear();
            cnt = 0;
            Dfs2(t.ff - 1, m, false);

            if(cnt == 2 * m - 1 && lst.ff == t.ff)
            {
                path.clear();
                Dfs(t.ff - 1, m);
                for(auto e = path.rbegin(); e != path.rend(); ++e)
                    ans.pb((*e + 2) % 4);

                for(auto e : r)ans.pb(e);

                path.clear();
                Dfs(lst.ff, lst.ss);
                for(auto e : path)ans.pb(e);

                return ans;
            }
            else
            {
                FOR(i, 1, n)FOR(j, 1, m)viz[i][j] = false;

                int x = n, y = 1;
                viz[x][y] = true;
                FOR(i, 1, n - 1)
                {
                    ans.pb(0);
                    x += dx[0], y += dy[0];
                    viz[x][y] = true;
                }
                ans.pb(1);
                x += dx[1], y += dy[1];
                viz[x][y] = true;

                FOR(i, 1, t.ff - 2)
                {
                    if(i % 2 == 1)
                    {
                        FOR(j, 2, m - 1)
                        {
                            ans.pb(1);
                            x += dx[1], y += dy[1];
                            viz[x][y] = true;
                        }
                    }
                    else
                    {
                        FOR(j, 2, m - 1)
                        {
                            ans.pb(3);
                            x += dx[3], y += dy[3];
                            viz[x][y] = true;
                        }
                    }
                    ans.pb(2);
                    x += dx[2], y += dy[2];
                    viz[x][y] = true;
                }

                st = 2, dr = m;
                s = t.ff - 1, j = t.ff;

                r.clear();
                cnt = 0;
                if(t.ff % 2 == 0)Dfs2(x, y, true);
                else Dfs2(x, y, false);

                for(auto e : r)ans.pb(e);

                path.clear();
                Dfs(lst.ff, lst.ss, 2);

                for(auto e : path)ans.pb(e);


                return ans;
            }
        }
    }
}

void write(vi const& pth)
{
    for(auto e : pth)fout << res[e];
    fout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tt = 1;
    cin >> tt;
    FOR(_, 1, tt)
    {
        cin >> m >> n;
        int n1 = n, m1 = m;

        string str;
        FOR(i, 1, n)
        {
            cin >> str;
            FOR(j, 1, m)
                if(str[j - 1] == 'X')
                {
                    t.ff = i;
                    t.ss = j;
                }
        }
        pii t1 = t;

//        auto r = solve();
//        if(!valid(r))
//        {
//            n = m1, m = n1;
//            t.ff = t1.ss, t.ss = (n1 - t1.ff + 1);
//            r = solve();
//
//            if(!valid(r))
//            {
//
//                n = n1, m = m1;
//                t.ff = (n1 - t1.ff + 1), t.ss = (m1 - t1.ss + 1);
//                r = solve();
//
//                if(!valid(r))
//                {
//                    n = m1, m = n1;
//                    t.ff = (n1 - t1.ff + 1), t.ss = t1.ff;
//                    r = solve();
//
//
//                    if(!valid(r))
//                    {
//                        cout << "ERROR AT " << _ << ' ' << n1 << ' ' << m1 << '\n';
//                    }
//                    else {for(auto& e : r)e = (e + 1) % 4;/// -3
//                            write(r);}
//                }
//                else {for(auto& e : r)e = (e + 2) % 4;/// -2
//                        write(r);}
//            }
//            else {for(auto& e : r)e = (e + 3) % 4;/// -1
//                    write(r);}
//        }
//        else write(r);
    }
    return 0;
}
