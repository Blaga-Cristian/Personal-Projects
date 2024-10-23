#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
ifstream cin("minime.in");
ofstream cout("minime.out");
const int N = 100009, M = 257,Inf = 0x3f3f3f3f;
string s;
vector<int> apariti;
vector<char> ans;
int n,m;
pair<int,int> best[M]; /// cel mai mic drum cu care se ajunge la m
int aux[M];
inline int mod(int a)
{
    if(a>=0)return a;
    return -a;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
        best[i].first = best[i].second = i;
    while(n--)
    {
        cin>>s;
        apariti.clear();
        char nr = 'z'+1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==nr)
                apariti.push_back(i);
            if(s[i]<nr)
                apariti.clear(),
                apariti.push_back(i),
                nr = s[i];
        }
        ans.push_back(nr);
        for(int i=0;i<M;++i)
        {
            if(aux[i]==0)
            {
                best[i] = {min(best[i].first,apariti[0]),max(best[i].second,apariti[0])};
            }
        }

        for(int x = 1;x<apariti.size();++x)
            for(int i=0;i<M;++i)
            {

            }


        for(int i=0;i<m;++i)
            if(best[i]==Inf)cout<<"oo ";
            else cout<<best[i]<<' ';
        cout<<'\n';
    }
    for(auto chr : ans)
        cout<<chr;
    cout<<'\n';
    int a = Inf;
    for(int i=0;i<m;++i)
        a = min(a,best[i]);
    cout<<a;
    return 0;
}
