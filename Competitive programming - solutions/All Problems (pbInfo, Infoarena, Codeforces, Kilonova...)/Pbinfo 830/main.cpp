#include <iostream>
#include <vector>
using namespace std;
int n,x,y;
bool apartine[10000];
void gen(int a)
{
    if(a<=n&&apartine[a]==false)
    {
       apartine[a]=true;
       gen(a+x);
       gen(a+y);
    }
}
int main()
{
    int a,i;
    cin>>n>>a>>x>>y;
    gen(a);
    for(i=0;i<=n;i++)if(apartine[i])cout<<i<<" ";
    return 0;
}
