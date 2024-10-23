#include <fstream>

using namespace std;
ifstream cin("immortal.in");
ofstream cout("immortal.out");
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int n,m,k,nrsoldati;
bool mapa[30][30],gata;
struct immortal{
int x,y;
}v[501];
struct miscari{
int i1,j1,i2,j2;
}miscare[501];
void afisare(int x)
{
    for(int i=0;i<x;++i)
    {
        cout<<miscare[i].i1<<' '<<miscare[i].j1<<' '<<miscare[i].i2<<' '<<miscare[i].j2<<'\n';
    }
}
bool inmat(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
void backt(int kp)
{
    if(nrsoldati==1&&!gata)afisare(kp),gata=1;
    else if(!gata)
    {
        for(int i=0;i<k;++i)
        {
            int x=v[i].x,y=v[i].y;
            if(mapa[v[i].x][v[i].y]==1)
            {
                for(int p=0;p<4;++p)
                {
                    int nx=v[i].x+di[p],ny=v[i].y+dj[p];
                    miscare[kp]={x,y,nx+di[p],ny+dj[p]};
                    if(inmat(nx,ny))
                    {
                        if(mapa[nx][ny]==1&&inmat(nx+di[p],ny+dj[p])&&mapa[nx+di[p]][ny+dj[p]]==0)
                        {
                            int nnx=nx+di[p],nny=ny+dj[p];
                                mapa[nx][ny]=0;
                                mapa[x][y]=0;
                                mapa[nnx][nny]=1;
                                v[i]={nnx,nny};
                                nrsoldati--;
                                if(nrsoldati>=1)backt(kp+1);
                                mapa[nx][ny]=1;
                                mapa[x][y]=1;
                                mapa[nnx][nny]=0;
                                v[i]={x,y};
                                nrsoldati++;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    nrsoldati=k;
    for(int i=0;i<k;++i)
    {
        cin>>v[i].x>>v[i].y;
        mapa[v[i].x][v[i].y]=1;
    }
    backt(0);
    return 0;
}
