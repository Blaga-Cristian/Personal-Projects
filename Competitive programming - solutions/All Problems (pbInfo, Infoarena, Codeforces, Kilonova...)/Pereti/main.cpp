#include <fstream>

using namespace std;
ifstream cin("pereti.in");
ofstream cout("pereti.out");
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int v[105][105],n,m,cnt=0;
void baza2(bool &N,bool &E,bool &S,bool &V,int nr)
{
    int cntr=4;
    while(nr!=0)
    {
        if(nr%2)
        {
            if(cntr==4)V=1;
            else if(cntr==3)S=1;
            else if(cntr==2)E=1;
            else if(cntr=1)N=1;
        }
        else
        {
            if(cntr==4)V=0;
            else if(cntr==3)S=0;
            else if(cntr==2)E=0;
            else if(cntr=1)N=0;
        }
        cntr--;
        nr=nr/2;
    }
}
void Fill(int i,int j)
{
    if(i>=0&&i<m&&j>=0&&j<n&&v[i][j]!=-1)
    {
        bool N=0,E=0,S=0,V=0;
        baza2(N,E,S,V,v[i][j]);
        v[i][j]=-1;
        cnt=cnt+N+E+S+V;
        if(!N)Fill(i+di[0],j+dj[0]);
        if(!E)Fill(i+di[1],j+dj[1]);
        if(!S)Fill(i+di[2],j+dj[2]);
        if(!V)Fill(i+di[3],j+dj[3]);
    }
}
int main()
{
    int i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    for(i=0,j=0;j<n;j++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(N) cnt++;
        }
    }
    for(j=0,i=0;i<m;i++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(V) cnt++;
        }
    }
    for(j=0,i=m-1;j<n;j++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(S)cnt++;
        }
    }
    for(j=n-1,i=0;i<m;i++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(E)cnt++;
        }
    }




    for(i=0,j=0;j<n;j++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(!N)Fill(i,j);
        }
    }
    for(j=0,i=0;i<m;i++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(!V)Fill(i,j);
        }
    }
    for(j=0,i=m-1;j<n;j++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(!S)Fill(i,j);
        }
    }
    for(j=n-1,i=0;i<m;i++)
    {
        if(v[i][j]!=-1)
        {
            bool N=0,E=0,S=0,V=0;
            baza2(N,E,S,V,v[i][j]);
            if(!E)Fill(i,j);
        }
    }
    cout<<cnt;
    return 0;
}
