#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

ifstream cin("regate.in");
ofstream cout("regate.out");

const int MAX = 2e5 + 3;

long long n , m , x , y , cost , v[MAX] , tin[MAX] , low[MAX] , timer , counter , cc[MAX] , k , ncc[MAX];

bitset <MAX> muchii;

bitset <MAX> b;

struct muchie{

    long long y , c , i;
};

struct bridge{

    long long x , y , c;

};

vector <muchie> g[MAX];

vector <bridge> bridges;

struct DSU{

    long long t[2*MAX] , h[2*MAX] , marss[2*MAX] , c[2*MAX];

    void init(){

        for(int i = 1 ; i <= n ; i++){

            t[i] = h[i] = marss[i] = c[i+n] = c[i] = 0;
        }
    }

    long long findc( long long a ){

        while( t[a] ){

             a = t[a];
        }

        return a;
    }

    void unionp( long long x , long long y , long long val ){

        if(h[x]==h[y]){

            marss[y] += c[x]*val;
            marss[x] += c[y]*val;
            marss[x] -= marss[y];

            t[x] = y;

            c[y] += c[x];

            c[x] = 0;

            h[y]++;

        }else{

            if(h[x] > h[y]) swap(x,y);

            marss[y] += c[x]*val;
            marss[x] += c[y]*val;
            marss[x] -= marss[y];


            t[x] = y;

            c[y] += c[x];

            c[x] = 0;
        }
    }

    long long cost( long long x ){

        long long sum = 0;

        while(x){

            sum = sum + marss[x];

            x = t[x];
        }

        return sum;
    }

    void update( long long x , long long val){

        c[x] = val;
    }

}uf;

void dfs( int x , int p ){

    tin[x] = low[x] = ++timer;

    b[x] = 1;

    for(auto it: g[x]){

        if(it.y == p) continue;

        if(b[it.y]){

            low[x] = min(low[x],tin[it.y]);

        }else{

            dfs(it.y,x);

            low[x] = min(low[x],low[it.y]);

            if(low[it.y] > tin[x]){

                muchii[it.i] = 1;

                bridges.push_back({x,it.y,it.c});
            }
        }
    }

}

vector <bridge> aux;

void dfs1( int x , int legatura , int marca){

    counter++;

    cc[x] = marca;

    aux.push_back({x+n,legatura,v[x]});

    for(auto it : g[x]){

        if(!muchii[it.i] && !cc[it.y]){

            dfs1(it.y,legatura,marca);
        }
    }

}

bool criteriu( bridge a , bridge b ){

    return (a.c > b.c);
}

int main()
{

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){

        cin >> v[i];
    }

    uf.init();

    counter = 0;

    while(m--){

        cin >> x >> y >> cost;

        ++counter;

        g[x].push_back({y,cost,counter});
        g[y].push_back({x,cost,counter});
    }

    dfs(1,0);

    k = 0;

    for(auto it : bridges){

        if(!cc[it.x]){

            counter = 0;

            ++k;

            dfs1(it.x,it.x,k);

            ncc[k] = it.x;

            uf.update(it.x,counter);
        }
        if(!cc[it.y]){

            counter = 0;

            ++k;

            dfs1(it.y,it.y,k);

            ncc[k] = it.y;

            uf.update(it.y,counter);
        }

        aux.push_back({ncc[cc[it.x]],ncc[cc[it.y]],it.c});
    }

    sort(aux.begin(),aux.end(),criteriu);

    for(auto br : aux){

        long long x = uf.findc(br.x);

        long long y = uf.findc(br.y);

        uf.unionp(x,y,br.c);
    }

    for(int i = 1 ; i <= n ; i++){

        cout << uf.cost(i+n) - v[i] << '\n';
    }

    return 0;
}
