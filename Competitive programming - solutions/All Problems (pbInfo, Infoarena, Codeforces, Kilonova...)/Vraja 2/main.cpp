#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int nr,cnt,x=0;
void program(int st,int dr)
{
    if(cnt!=0)
    {
        x++;
        int i,min=9999999,ok=0,st1,dr1;
        for(i=st;i<=dr;i++)
        {
            if(v[i]<min&&v[i]!=0)min=v[i];
        }
        for(i=st;i<=dr;i++)
        {
            v[i]=v[i]-min;
            if(v[i]==0)
            {
                cnt--;
                if(ok==1)
                {
                    //cout<<st1<<" "<<dr1<<endl;
                    ok=0;
                    program(st1,dr1);
                }
            }
            else if(ok==0)
            {
                st1=i;
                dr1=i;
                ok=1;
                if(i==dr)
                {
                    //cout<<st1<<" "<<dr1<<endl;
                    program(st1,dr1);
                }
            }
            else if(ok==1)
            {
                dr1=i;
                if(i==dr)
                {
                    //cout<<st1<<" "<<dr1<<endl;
                    program(st1,dr1);
                }
            }
        }
    }
}
int main()
{
    int a,b,i;
    cin>>a;
    nr=a;
    cnt=nr;
    for(i=1;i<=a;i++)
    {
        cin>>b;
        v.push_back(b);
    }
    program(0,a-1);
    cout<<x;
    return 0;
}
