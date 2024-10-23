#include <iostream>

using namespace std;
int n;
int p[11][11],v[11][11];
void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(v[i][j]==0)cout<<"- ";
            else cout<<"* ";
        }
        cout<<endl;
    }
    //for(int i=1;i<=n;i++)
    {
        //for(int j=1;j<=n;j++)
        {
            //cout<<p[i][j]<<" ";
        }
        //cout<<endl;
    }
    //cout<<endl<<endl;
}
void deselectare(int x,int y)
{
    int i,j;
    v[x][y]=0;
    for(i=x,j=1;j<=n;j++)p[i][j]-=1;
    for(j=y,i=1;i<=n;i++)if(i!=x)p[i][j]-=1;
    for(i=x+1,j=y+1;i<=n&&j<=n;i++,j++)p[i][j]-=1;
    for(i=x-1,j=y-1;i>=1&&j>=1;i--,j--)p[i][j]-=1;
    for(i=x-1,j=y+1;i>=1&&j<=n;i--,j++)p[i][j]-=1;
    for(i=x+1,j=y-1;i<=n&&j>=1;i++,j--)p[i][j]-=1;
}
void selectare(int x,int y)
{
    int i,j;
    v[x][y]=1;
    for(i=x,j=1;j<=n;j++)p[i][j]+=1;
    for(j=y,i=1;i<=n;i++)if(i!=x)p[i][j]+=1;
    for(i=x+1,j=y+1;i<=n&&j<=n;i++,j++)p[i][j]+=1;
    for(i=x-1,j=y-1;i>=1&&j>=1;i--,j--)p[i][j]+=1;
    for(i=x-1,j=y+1;i>=1&&j<=n;i--,j++)p[i][j]+=1;
    for(i=x+1,j=y-1;i<=n&&j>=1;i++,j--)p[i][j]+=1;
}
void backtracking(int x,int y,int nr)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(p[i][j]==0)
            {
                selectare(i,j);
                //afisare();
                if(nr==n)
                {
                    afisare();
                    return;
                }
                else backtracking(i,j,nr+1);
                deselectare(i,j);
                break;
            }
        }
    }
}
int main()
{
    cin>>n;
    backtracking(1,1,1);
    //selectare(1,3);
    //selectare(2,1);
    //selectare(3,4);
    //selectare(4,2);
    //deselectare(1,3);
    //deselectare(2,1);
    return 0;
}
