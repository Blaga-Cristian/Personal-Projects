#include <bits/stdc++.h>
#include <bits/extc++.h>
#define MP make_pair
#define MT make_tuple
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
#define fast_in_out ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define REP(i,a,b) for(int i = a; i <= b; ++i)
template <typename T>
using indexed_set = __gnu_pbds::tree <T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


using namespace std;
typedef array<int,3> triple;

const int Inf = 0x3f3f3f3f, N = 1e5 + 9, V = 109;
const int Mod = 1e9 + 7;

int t,n;

class matrix
{
private:
    ll mat[2][2];
public:
    matrix()
    {}

    matrix(ll a,ll b,ll c,ll d)
    {mat[0][0] = a, mat[0][1] = b, mat[1][0] = c, mat[1][1] = d;}

    matrix operator * (matrix b)
    {
        return matrix((mat[0][0] * b.mat[0][0] + mat[0][1] * b.mat[1][0]) % Mod,
                      (mat[0][0] * b.mat[1][0] + mat[0][1] * b.mat[1][1]) % Mod,
                      (mat[1][0] * b.mat[0][0] + mat[1][1] * b.mat[1][0]) % Mod,
                      (mat[1][0] * b.mat[0][1] + mat[1][1] * b.mat[1][1]) % Mod);
    }

    ll sum()
    {
        return mat[0][0] + mat[1][0] + mat[0][1] + mat[1][1];
    }
};

matrix power(matrix x, int exp)
{
    matrix ans(1,0,0,1);
    matrix baza = x;
    while(exp)
    {
        if(exp & 1)
            ans = ans * baza;

        baza = baza * baza;
        exp >>= 1;
    }

    return ans;
}

int main()
{
    matrix a(1, 1, 0, 0);
    matrix b(2, 1, 1, 4);
    cin >> t;
    while(t --)
    {
        cin >> n;
        matrix ans = a * power(b, n - 1);
        cout << ans.sum() % Mod << '\n';
    }
    return 0;
}
