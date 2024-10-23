#include <bits/stdc++.h>
using namespace std;
ifstream f("pulsar.in");
ofstream g("pulsar.out");
const int di[]={-1,1,0,0,0},dj[]={0,0,-1,1,0};


int a[65][505][505];
bool viz [65][505][505];
long long c,n,p,cmmmc=1,xs,ys,xf,yf,r;
struct pulsari{
    long long x,y,r,t;
}v[15005];
struct triple{
    long long x,y,stare,val;
};
int lcm(int a,int b)
{
    return a*b/__gcd(a, b);
}
int manhattan(int xs, int ys, int xf,int yf){
    return abs(xf-xs)+abs(yf-ys);
}
bool verif(int a,int b)
{
    return a>=1&&a<=n&&b>=1&&b<=n;
}
void fillM(int xc, int yc, int raza, int stare, int xstart, int ystart){
    a[stare][xc][yc]=1;
    if(manhattan(xc,yc,xstart,ystart)<r)
    {
    for(int k=0;k<4;k++)
    {
        if(verif(xc+di[k],yc+dj[k])&&manhattan(xc,yc,xstart,ystart)<manhattan(xstart,ystart,xc + di[k],yc + dj[k]))
            fillM(xc+di[k],yc+dj[k],raza,stare,xstart,ystart);
    }
    }
}
int main()
{
    int i,j;
    f>>c>>n>>p;
    for(i=1;i<=p;i++)
    {
        f>>v[i].x>>v[i].y>>v[i].r>>v[i].t;
        cmmmc=lcm(cmmmc,v[i].r);
    }
    f>>xs>>ys>>xf>>yf;
    for(i=0;i<cmmmc;i++)
    {
        for(j=1;j<=p;j++)
        {
            r=(i+v[j].t)%v[j].r;
            fillM(v[j].x,v[j].y,r,i,v[j].x,v[j].y);
        }
    }
    if(c==1)
    {
        int mx=0;
        for(i=0;i<cmmmc;i++)
        {
            int nr=0;
            for(j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                    if(a[i][j][k]==1)nr++;
            }
            mx=max(mx,nr);
        }
        g<<mx;
    }
    else
    {
        queue<triple>q;
        q.push({xs,ys,0});
        viz[0][xs][ys]=1;
        triple now;
        while(!q.empty())
        {
            now = q.front();
            if(now.x==xf&&now.y==yf)break;
            q.pop();
            for(int k=0;k<=4;k++)
            {
                triple nxt = {now.x+di[k],now.y+dj[k],(now.stare+1)%cmmmc,now.val+1};
                if(verif(nxt.x,nxt.y)&&a[nxt.stare][nxt.x][nxt.y]!=1&&viz[nxt.stare][nxt.x][nxt.y]==0)
                {
                    viz[nxt.stare][nxt.x][nxt.y]=1;
                    q.push(nxt);
                }
            }
        }
        g<<now.val;
    }
    return 0;
}
