#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, tt, s1, s2, tmax;
vector<int> v[maxn];

void generateTree()
{
    for(int i=2; i<=n; ++i)
    {
        int x = rand()%(i-1) + 1;
        v[x].push_back(i);
        v[i].push_back(x);
    }
}

void generateChain()
{
    for(int i=2; i<=n; ++i)
    {
        int x = i-1;
        v[x].push_back(i);
        v[i].push_back(x);
    }
}

int main(int argc, char *argv[])
{
    freopen("sushi.in", "w", stdout);

    if(argc!=7)
    {
        fprintf(stderr, "Too few arguments on command line, insert parameters manually:\n");
        scanf("%d%d%d%d%d%d", &n, &m, &tt, &s1, &s2, &tmax);
    }
    else
    {
        n=atoi(argv[1]);
        m=atoi(argv[2]);
        tt=atoi(argv[3]);
        s1=atoi(argv[4]);
        s2=atoi(argv[5]);
        tmax=atoi(argv[6]);
    }

    srand(time(0));

    printf("%d %d\n", n, m);

    if(tt==0)
        generateTree();
    else
        generateChain();

    for(int i=1; i<=n; ++i)
    {
        printf("%d ", v[i].size());
        for(int j=0; j<v[i].size(); ++j)
            printf("%d ", v[i][j]);
        printf("\n");
    }

    for(int i=1; i<=m; ++i)
    {
        int tm = rand()%(tmax+1);
        if(s1==1 && i==1)
        {
            printf("%d %d %d\n", 1, 1, tm);
            continue;
        }
        if(s2==1 && i==2)
        {
            printf("%d %d %d\n", 1, v[1].size(), tm);
            continue;
        }

        int nod = rand()%n+1;
        int poz = rand()%v[nod].size()+1;

        printf("%d %d %d\n", nod, poz, tm);
    }

    return 0;
}
