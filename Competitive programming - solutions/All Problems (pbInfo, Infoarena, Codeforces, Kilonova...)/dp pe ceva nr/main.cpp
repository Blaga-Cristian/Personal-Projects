#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
#define LE 0
#define EQ 1
using namespace std;
ull a,b;
ull cnt[20][200][2];
vector<int> primes;
inline bool prime(int x)
{
    if(x<=1)return false;
    if(x<=3)return true;
    if(x%2==0||x%3==0)return false;
    for(int i=5;i*i<=x;i+=6)
        if(x%i==0||x%(i+2)==0)return false;
    return true;
}
ull countless(ull x)
{
    for(int i=0;i<20;++i)
        for(int j=0;j<200;++j)
            cnt[i][j][LE] = cnt[i][j][EQ] = 0;

    vector<int> N;
    while(x)N.push_back(x%10),x/=10;
    reverse(N.begin(),N.end());
    cnt[0][0][EQ] = 1;
    int prevsum = 0;
    for(int nrcif = 0; nrcif < N.size();++nrcif)
    {
        for(int sumcif = 0;sumcif<200;++sumcif)
            for(int nextcif = 0; nextcif <= 9; ++nextcif)
                cnt[nrcif+1][sumcif+nextcif][LE] += cnt[nrcif][sumcif][LE];
        cnt[nrcif+1][prevsum + N[nrcif]][EQ] += cnt[nrcif][prevsum][EQ];
        for(int nextcif = 0;nextcif < N[nrcif];++nextcif)
            cnt[nrcif+1][prevsum + nextcif][LE] += cnt[nrcif][prevsum][EQ];
        prevsum+=N[nrcif];
    }
    ull ans = 0;
    for(auto p : primes)
        ans += cnt[N.size()][p][LE];
    return ans;
}
ull countless(ull a,ull b)
{
    return countless(b+1) - countless(a);
}
int main()
{
    for(int i=1;i<200;++i)
        if(prime(i))primes.push_back(i);
    cin>>a>>b;
    if(a>b)swap(a,b);
    cout<<countless(a,b);
    return 0;
}
