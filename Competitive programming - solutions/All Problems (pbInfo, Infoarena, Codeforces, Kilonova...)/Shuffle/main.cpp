#include <fstream>
#include <algorithm>
#include <tuple>
using namespace std;
ifstream cin("shuffle.in");
ofstream cout("shuffle.out");
int n,b[10];
tuple<int,int,int>v[10];
bool p[10];
bool f(tuple<int,int,int>a,tuple<int,int,int>b)
{
    return get<1>(a)<get<1>(b);
}
void afisare()
{
    int ok=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(get<1>(v[b[i+1]])==get<0>(v[b[i]])||get<1>(v[b[i+1]])==get<2>(v[b[i]]))ok=1;
        }
        else if(i==n-1)
        {
            if(get<1>(v[b[i-1]])==get<0>(v[b[i]])||get<1>(v[b[i-1]])==get<2>(v[b[i]]))ok=1;
        }
        else
        {
            if(get<1>(v[b[i+1]])==get<0>(v[b[i]])||get<1>(v[b[i+1]])==get<2>(v[b[i]])||get<1>(v[b[i-1]])==get<0>(v[b[i]])||get<1>(v[b[i-1]])==get<2>(v[b[i]]))ok=1;
        }
    }
    if(ok==0)
    {
        for(int i=0;i<n;i++)cout<<get<1>(v[b[i]])<<" ";
        cout<<'\n';
    }
}
void backtracking(int x)
{
    for(int i=0;i<n;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==n-1)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>get<1>(v[i]);
        if(i==0)
        {
            get<0>(v[i])=0;
        }
        else if(i==n-1)
        {
            get<0>(v[i])=get<1>(v[i-1]);
            get<2>(v[i-1])=get<1>(v[i]);
            get<2>(v[i])=0;
        }
        else
        {
            get<0>(v[i])=get<1>(v[i-1]);
            get<2>(v[i-1])=get<1>(v[i]);
        }
    }
    if(n<4)cout<<"nu exista";
    else{
    sort(v,v+n,f);
    backtracking(0);}
    return 0;
}
