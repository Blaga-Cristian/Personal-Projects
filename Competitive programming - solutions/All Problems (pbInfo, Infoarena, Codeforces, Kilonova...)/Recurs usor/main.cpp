#include <iostream>
#include <vector>
using namespace std;
vector<unsigned long long int> v;
void deal(int nr)
{
    if(nr<v.size())
    {
        int nr1=nr;
        while(v[nr1]<=v[nr1+1]&&nr1<v.size()-1)nr1++;
        for(int i=nr1;i>=nr;i--)cout<<v[i]<<" ";
        deal(nr1+1);
    }
}
int main()
{
    unsigned long long int a;
    cin>>a;
    while(a!=0)
    {
        v.push_back(a);
        cin>>a;
    }
    //for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    deal(0);
    return 0;
}
