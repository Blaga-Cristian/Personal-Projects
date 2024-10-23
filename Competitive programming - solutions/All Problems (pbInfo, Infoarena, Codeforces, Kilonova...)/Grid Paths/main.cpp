#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
using namespace std;
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
string s;
bool viz[8][8];
int ans;

inline bool valid(int x,int y)
{
    return (x >= 1 && x <= 7) && (y >= 1 && y <= 7) && (viz[x][y] == false);
}

void Back(int nr, int x, int y)
{
    if(x == 7 && y == 1)
    {
        if(nr == 49)
            ans++;
        return;
    }

    if(!valid(x + dx[0], y + dy[0])&&
       !valid(x + dx[2], y + dy[2])&&
       valid(x + dx[1], y + dy[1])&&
       valid(x + dx[3], y + dy[3]))
        return;
    if(valid(x + dx[0], y + dy[0])&&
       valid(x + dx[2], y + dy[2])&&
       !valid(x + dx[1], y + dy[1])&&
       !valid(x + dx[3], y + dy[3]))
        return;

    if(s[nr-1] == '?')
    {
        for(int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(valid(nx,ny))
            {
                viz[nx][ny] = true;
                Back(nr+1,nx,ny);
                viz[nx][ny] = false;
            }
        }
    }
    else
    {
        int nx = x, ny = y;
        if(s[nr-1] == 'U')
            nx += dx[0], ny += dy[0];
        if(s[nr-1] == 'R')
            nx += dx[1], ny += dy[1];
        if(s[nr-1] == 'D')
            nx += dx[2], ny += dy[2];
        if(s[nr-1] == 'L')
            nx += dx[3], ny += dy[3];

        if(valid(nx,ny))
        {
            viz[nx][ny] = true;
            Back(nr + 1, nx, ny);
            viz[nx][ny] = false;
        }
    }
}

int main()
{
    cin>>s;
    viz[1][1] = true;
    Back(1,1,1);
    viz[1][1] = false;
    cout<<ans;
    return 0;
}
