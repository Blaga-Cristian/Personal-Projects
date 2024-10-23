#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300009;
int n;
struct element
{
    int val;
    string s;
};
inline bool cmp(element a,element b)
{
    return a.val == b.val ? a.s < b.s : a.val < b.val;
}
element v[N];
int main()
{
    scanf("%d",&n);
    for(int i =1; i <=n;++i)
    {
        scanf("%s",&v[i].s.c_str());
        for(int j = 0; j < v[i].s.size()-1;++j)
        {
            if(strchr("aeiouAEIOU",v[i].s[j])!= 0 && strchr("aeiouAEIOU",v[i].s[j+1])!= 0)
                v[i].val ++;
            if(strchr("aeiouAEIOU",v[i].s[j]) == 0 && strchr("aeiouAEIOU",v[i].s[j+1]) == 0)
                v[i].val --;
        }
    }
    sort(v+1,v+n+1,cmp);
    for(int i = 1; i <= n; ++i)
        printf("%s\n",v[i].s.c_str());
    return 0;
}
