#include <iostream>

using namespace std;

int main()
{
    const int max=99;
    int vec[max],i,n;
    do{cout<<"/nNr. elemente=";
    cin>>n;}
    while(n>99);
    for(i=0;i<n;i++)vec[i]=i;
    for(i=0;i<n;i++)cout<<vec[i]<<endl;
    return 0;
}
