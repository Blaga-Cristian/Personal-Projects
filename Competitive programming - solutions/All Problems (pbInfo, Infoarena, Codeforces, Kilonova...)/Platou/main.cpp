#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <queue>
using namespace std;
const int Inf = 0x3f3f3f3f;
int n,k,x,y,p;
struct element
{
    int sum;
    priority_queue<int,vector<int>,greater<int>>q;
};
unordered_map<int,element>mp;

const int DIM = 10000;
char buff[DIM + 5];
int poz;
inline void read(int &numar)
{
     numar = 0;
     while (buff[poz] < '0' || buff[poz] > '9')
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
     while ('0' <= buff[poz] && buff[poz] <= '9')
     {
        numar = numar * 10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
     }
}
int main()
{
    read(k);
    read(n);
    int prv,val;
    read(prv);
    val = 1;
    for(int i = 2; i <= n; ++i)
    {
        read(x);
        if(x == prv)
            val++;
        else
        {
            mp[prv].q.push(val);
            mp[prv].sum+=val;
            if(mp[prv].q.size() > k)
            {
                mp[prv].sum -= mp[prv].q.top();
                mp[prv].q.pop();
            }
            prv = x;
            val = 1;
        }
    }

    int ans = -1,valans = -1;
    for(auto i : mp)
    {
        if(i.second.sum > ans)
        {
            ans = i.second.sum;
            valans = i.first;
        }
        else if(i.second.sum == ans && i.first > valans)
        {
            valans = i.first;
        }
    }

    read(p);
    if(p == 1)
        cout<<ans;
    else
        cout<<valans;
    return 0;
}
