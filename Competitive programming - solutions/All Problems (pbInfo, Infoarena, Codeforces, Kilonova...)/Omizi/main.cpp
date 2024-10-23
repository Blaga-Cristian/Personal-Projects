#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("omizi.in");
ofstream cout("omizi.out");
const int N = 16009;
int n,m,a,b,x,y,cnt;
int nod;
char s;
int lin[2][N],pos[2][N],dep[N];
int query_type[2][N];
int tree[2][4*N];
pair<int,int> segment[2][N];
vector<vector<int>>sirad;
int answer[N];

void lini(int x,int tip)
{
    segment[tip][x].first = cnt + 1;
    for(auto i : sirad[x])
            lini(i,tip);
    lin[tip][++cnt] = x;
    pos[tip][x] = cnt;
    segment[tip][x].second = cnt;
}


void update(int nod,int st,int dr,bool tip,int poz)
{
    if(st == dr)
    {
        tree[tip][nod] = 1;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz <= mij)
        update(nod<<1,st,mij,tip,poz);
    else
        update(nod<<1|1,mij+1,dr,tip,poz);

    tree[tip][nod] = tree[tip][nod<<1] + tree[tip][nod<<1|1];
}
int query(int type, int node, int left, int right, int query_left, int query_right)
{
  if (query_left <= left and right <= query_right) {
    if (tree[type][node] == right - left + 1)
      return -1;
    if (left == right) {
      return left;
    } else {
      int middle = (left + right) / 2,
          left_son = node * 2,
          right_son = node * 2 + 1;

      if (tree[type][left_son] != middle - left + 1)
        return query(type, left_son, left, middle, query_left, query_right);
      else
        return query(type, right_son, middle + 1, right, query_left, query_right);
    }
  } else {
    int middle = (left + right) / 2,
        left_son = node * 2,
        right_son = node * 2 + 1;

    int answer = -1;

    if (query_left <= middle)
      answer = query(type, left_son, left, middle, query_left, query_right);
    if (answer != -1)
      return answer;
    if (middle + 1 <= query_right)
      answer = query(type, right_son, middle + 1, right, query_left, query_right);

    return answer;
  }
}
void dfs(int node,int n)
{
    for(int son : sirad[nod])
        dfs(son,n);

    for(int type = 0; type <= 1; ++type)
        if(query_type[type][node] != 0)
    {
        int position = query(type,1,1,n,segment[type][nod].first,segment[type][nod].second);

        int position_node = lin[type][position];
        int opposite_position = pos[1-type][position_node];

        answer[query_type[type][node]] = position_node;
        //update(1,1,n,type,position);
        //update(1,1,n,1-type,opposite_position);
    }
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    for(int i = 1; i <= n;++i)
    {
        while(true)
        {
            cin >> x;
            if(x == 0)break;
            sirad[i].push_back(x);
        }
    }

    cnt = 0;
    lini(1,0);
    for(int i = 1; i <= n; ++i)
        reverse(begin(sirad[i]),end(sirad[i]));
    cnt = 0;
    lini(1,1);

    for(int i = 1; i <= m; ++i)
    {
        int x;
        char s;
        cin>>x>>s;
        if(s == 'S')
            query_type[0][x] = i;
        else
            query_type[1][x] = i;
    }

    dfs(1,n);
    for(int i = 1; i <= m; ++i)
        cout<<answer[i]<<'\n';
    return 0;
}
