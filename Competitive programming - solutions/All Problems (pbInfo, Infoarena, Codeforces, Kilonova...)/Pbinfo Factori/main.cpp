#include <bits/stdc++.h>
using namespace std;
ifstream fin("factori.in");
ofstream fout("factori.out");
int main()
{
    int v[60001]={0} , n ;
    fin >> n;
    while(n != 0)
    {
        for(int i = 1 ; i <= n ; ++i) v[i] = 0;
        for(int i = 1 ; i <= n ; ++i)
        {
            int aux = i , d = 2;
            while(aux > 1)
            {
                int p = 0;
                while(aux % d == 0) p++, aux /= d;
                if(p) v[d] += p;
                d++;
                if(d*d > aux) d=aux;
            }
        }
        for(int j = 1  ; j <= n ; ++j)
            if(v[j] != 0)fout << v[j] << " ";
        fout << endl;
        fin >> n;
    }
    return 0;
}
