#include <iostream>

using namespace std;
int nr_cif(int n,int k)
{
    int s=0;
    while(n!=0)
    {
        if(n%10>=1)
        {
            if(k%(n%10)==0)s++;
        }
        n=n/10;
    }
    return s;
}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<nr_cif(x,y);
    return 0;
}
