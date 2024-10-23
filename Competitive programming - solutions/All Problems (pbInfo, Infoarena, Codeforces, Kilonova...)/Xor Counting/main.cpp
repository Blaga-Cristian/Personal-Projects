#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
const int Mod = 998244353,MOD = Mod;

unordered_map <long long int,long long int> npos,spos;

ll solve(ll n)
{
    if(npos[n] != 0)
        return spos[n];

    if(n % 2 == 1)
    {
        solve(n/2);
        npos[n] = npos[n/2];
        spos[n] = spos[n/2] * 2 + npos[n/2];
        spos[n] %= Mod;
    }
    else
    {
        solve(n/2); solve(n/2 - 1);
        npos[n]=npos[n/2]+npos[n/2-1];
        spos[n]=(spos[n/2]+spos[n/2-1])*2;
        spos[n]%=Mod;
    }

    return spos[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    npos[0]=1;
    spos[0]=0;
    int t;
    cin >> t;
    while(t--){
        long long int n,m;
        cin >> n >> m;
        if(m==2){
            cout << solve(n) << endl;
        }
        else if(m==1){
            cout << n%MOD << endl;
        }
        else if(n%2==0){
            cout << (((n/2)%MOD)*((n/2+1)%MOD))%MOD << endl;
        }
        else{
            cout << (((n/2+1)%MOD)*((n/2+1)%MOD))%MOD << endl;
        }
    }
}
