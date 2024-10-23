#include <fstream>

using namespace std;
ifstream cin("amongus.in");
ofstream cout("amongus.out");
const int di[]={-1,-1,-1,0,0,1,1,1},dj[]={-1,0,1,-1,1,-1,0,1};
int s[101][101],n,m,cnt3=0;
void Fill(int i ,int j ,int v)
{
    // i,j - elementul curent, v - valoarea cu care facem Fill
    if(i >= 1 && i <= n && j >= 1 && j <= m &&( s[i][j] == 0 || s[i][j]==2))
    {   // in matrice, element liber si nemarcat
        if(s[i][j]==2)cnt3++;
        s[i][j] = v;
        for(int k = 0 ; k < 8 ; k ++)
            Fill(i + di[k] , j + dj[k], v);
    }
}

int main()
{
    int p,cnt=0,i,j;
    cin>>p>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>s[i][j];
            if(s[i][j]==0)cnt++;
        }
    }
    if(s[1][1]==1)cout<<"misiune esuata";
    else
    {if(p==1)cout<<cnt;
    else if(p==2)
    {
        Fill(1,1,3);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cout<<s[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(p==3)
    {
        Fill(1,1,3);
        cout<<cnt3;
    }}
    return 0;
}
