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
const int Mod = 1e9 + 7;

char s[20];
int n;

void Back(int x)
{
    if(x == n)
    {
        cout<<s<<'\n';
        return;
    }
    Back(x+1);
    s[x] == '0' ? s[x] = '1' : s[x] = '0';
    Back(x+1);
}

int main()
{
    cin>>n;
    memset(s,'0',n);
    Back(0);
    return 0;
}
