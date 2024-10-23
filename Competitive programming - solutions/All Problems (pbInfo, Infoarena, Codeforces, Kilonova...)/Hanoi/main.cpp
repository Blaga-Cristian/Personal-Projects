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

int n;

void Build(int x,int A,int B,int C)
{
    if(x == 0)return;
    Build(x-1,A,C,B);
    cout<<A<<' '<<C<<'\n';
    Build(x-1,B,A,C);
}

int main()
{
    cin>>n;
    cout<<pow(2,n) - 1<<'\n';
    Build(n,1,2,3);
    return 0;
}
