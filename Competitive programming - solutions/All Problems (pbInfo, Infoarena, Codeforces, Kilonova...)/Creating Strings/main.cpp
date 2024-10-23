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

string str;
int frecv[26];
char s[20];
int n;
int fact[20];
void precalc()
{
    fact[0] = 1;
    for(int i = 1; i <= 12; ++i)
        fact[i] = fact[i-1] * i;
}

void Back(int x)
{
    if(x == n)
    {
        cout<<s<<'\n';
        return;
    }
    for(int i = 0; i < 26; ++i)
        if(frecv[i])
    {
        frecv[i]--;
        s[x] = 'a' + i;
        Back(x+1);
        frecv[i]++;
    }
}

int main()
{
    precalc();
    cin>>str;
    n = str.size();
    for(int i = 0; i < n; ++i)
        frecv[str[i]-'a']++;

    int cnt = fact[n];
    for(int i = 0; i < n; ++i)
        cnt /= fact[frecv[i]];
    cout<<cnt<<'\n';
    Back(0);
    return 0;
}
