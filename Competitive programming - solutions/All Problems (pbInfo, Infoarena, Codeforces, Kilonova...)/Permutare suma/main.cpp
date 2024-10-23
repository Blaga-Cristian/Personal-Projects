#include <iostream>
#include <algorithm>
using namespace std;
int n,b[20],k=1,c[20];
long long sum=0;
bool p[20];
void adaugare()
{
    int nr=0;
    for(int i=1;i<k;i++)
    {
        nr = nr*10+b[c[i]];
    }
    sum=sum+nr;
}
void backtracking(int x)
{
    for(int i=1;i<k;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            c[x]=i;
            if(x==k-1)adaugare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    int nr = n;
    while(nr!=0)
    {
        b[k]=nr%10;
        nr=nr/10;
        k++;
    }
    reverse(b+1,b+k);
    backtracking(1);
    cout<<sum;
    return 0;
}
