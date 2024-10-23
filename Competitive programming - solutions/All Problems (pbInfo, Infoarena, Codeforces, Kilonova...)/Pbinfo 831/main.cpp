#include <iostream>
#include <vector>
using namespace std;
vector<bool>a;
int n,b=0;
void gen(int n)
{
    if(b!=n)
    {
        if(a[b]==false)
        {
            a[b]=true;
            for(int i=n-1;i>=0;i--)
            {
                cout<<a[i];
            }
            cout<<'\n';
            b--;
        }
        else if(a[b]==true&&a[b+1]==false)
        {
            a[b+1]=true;
            for(int i=b;i>=0;i--)a[i]=false;
            for(int i=n-1;i>=0;i--)
            {
                cout<<a[i];
            }
            cout<<'\n';
        }
        b++;
        gen(n);
    }
}
int main()
{
    cin>>n;
    bool c=false;
    for(int i=0;i<=n+1;i++)a.push_back(c);
    for(int i=0;i<n;i++)cout<<'0';
    cout<<'\n';
    gen(n);
    return 0;
}
