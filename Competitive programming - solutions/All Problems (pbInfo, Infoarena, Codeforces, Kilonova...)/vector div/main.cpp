#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int v[100];
int divi[100],n,mini=9999999999,len,b[100];
vector<vector<int> >vec;
void afisare(int* a,int len)
{
    for(int i=0;i<len;++i)cout<<a[i]<<' ';
    cout<<'\n';
}
void backtrack(int x,int cnt)
{
    if(x==-1)
    {
        mini=min(mini,cnt);
    }
    else
    {
        for(int i=vec[b[x+1]].size()-1;i>=0&&(cnt<mini);--i)
        {
            b[x]=vec[b[x+1]][i];
            backtrack(x-1,cnt+abs(v[x]-b[x]));
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    vec = vector<vector<int> >(v[n-1]+1);
    for(int i=2;i*i<=v[n-1];++i)
    {
        if(v[n-1]%i==0)
        {
            vec[v[n-1]].push_back(i);
            if(i*i<v[n-1])vec[v[n-1]].push_back(v[n-1]/i);
        }
    }
    vec[v[n-1]].push_back(1);
    vec[v[n-1]].push_back(v[n-1]);
    sort(vec[v[n-1]].begin(),vec[v[n-1]].end());
    for(int i=vec[v[n-1]].size()-2;i>=0;--i)
    {
        for(int j=0;j<=i;++j)
        {
            if(vec[v[n-1]][i]%vec[v[n-1]][j]==0)
            {
                vec[vec[v[n-1]][i]].push_back(vec[v[n-1]][j]);
            }

        }
    }
    b[n-1]=v[n-1];
    //backtrack(n-2,0);
    cout<<mini;
    return 0;
}
