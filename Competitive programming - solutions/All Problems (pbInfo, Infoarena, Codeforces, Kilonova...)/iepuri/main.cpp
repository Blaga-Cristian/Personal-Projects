#include <fstream>
#include <vector>
using namespace std;
ifstream cin("iepuri.in");
ofstream cout("iepuri.out");
const int N = 109, MOD = 30011;
int n,k,a,b,root,K;
using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VI t;

VI Dfs(int x)
{
    VI X(k+1,1);
    for(auto& f : G[x])
    {
        VI V = Dfs(f);
        VI aux(k+1,0);

        for(int i = 1; i <= k; ++i)
            for(int j = i+1; j <= k; ++j)
                aux[i] += X[i] * V[j];

        X = aux;
    }
    return X;
}

VI DF(int x)
{
	VI rx(K + 1, 1); // rx[i] = nr de moduri de a plasa val in subarb cu rad in x, daca in x plasez val i

	for (const int& son : G[x])
	{
		VI rs = DF(son);
		VI tmp(K + 1);
		for ( int i = 1; i <= K; ++i )   // citi are nod
			for ( int j = i + 1; j <= K; ++j) // cati are son
			{
				tmp[i] +=  (rs[j] * rx[i]) % MOD;
				tmp[i] %= MOD;
			}
		rx = tmp;
	}
	return rx;
}
int main()
{
    cin>>n>>k;
    K = k;
    G = VVI(n+1);
    t = VI(n+1);
    for(int i = 1;i < n; ++i)
    {
        cin>>a>>b;
        G[a].push_back(b);
        t[b] = a;
    }

    for(int i = 1; i <= n; ++i)
        if(t[i] == 0)
    {
        root = i;
        break;
    }

    VI ans = Dfs(root);

    int rez = 0;
    for(int i = 1; i <= k; ++i)
        rez += ans[i];
    cout<<rez;
    return 0;
}
