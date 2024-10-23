#include <fstream>

using namespace std;
ifstream cin("graf_complet.in");
ofstream cout("graf_complet.out");
int main()
{
    int n;
    cin>>n;
    for(int k=1;k<=n;++k)
    {
        int nr,a;
        cin>>nr;
        for(int i=1;i<=nr;++i)
        {
            for(int j=1;j<=nr;++j)
            {
                cin>>a;
                if(i==j&&a!=0)
                {
                    ok=0;

                }
                else if(i!=j&&a!=1)
                {
                    ok=0;

                }
            }
        }
        if(ok==0)cout<<"NU\n";
        else cout<<"DA\n";
    }
    return 0;
}
