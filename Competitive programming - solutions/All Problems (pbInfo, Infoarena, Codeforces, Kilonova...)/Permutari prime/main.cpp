#include <iostream>
#include <algorithm>
using namespace std;
int n,k=1,l=1,pos[20],v[20],a[20];
pair<int,int> b[20];
bool p[20];
bool prim(int a)
{
    if(a==0||a==1)return false;
    else if(a==2)return true;
    else if(a%2==0)return false;
    else
    {
        for(int i=3;i*i<=a;i+=2)
        {
            if(a%i==0)return false;
        }
    }
    return true;
}
void afisare()
{
    int j=1,nr=1;
    for(int i=1;nr<=n;i++,nr++)
    {
        if(nr==b[j].first)
        {
            cout<<b[j].second<<" ";
            j++;
            i--;
        }
        else cout<<a[v[i]]<<" ";
    }
    cout<<endl;
}
void backtracking(int x)
{
    for(int i=1;i<l;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            v[x]=i;
            if(x==l-1)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    int x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(prim(x))
        {
            b[k].first=i;
            b[k].second=x;
            k++;
        }
        else
        {
            a[l]=x;
            l++;
        }
    }
    sort(a+1,a+l);
    backtracking(1);
    return 0;
}
