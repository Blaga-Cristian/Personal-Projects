#include <fstream>

using namespace std;
ifstream cin("heapuri.in");
ofstream cout("heapuri.out");
const int N = 200009;
int H[N],size,cnt;
int pos[N];//ii ccer ord cronologica iti da pozitia in heap
int inv[N]; // ii ceri pozitia in heap si itt da al catele e in ord cronologica
void sift(int x)
{
    int son;
    do
    {
        son = 0;
        if(x*2 <= size)
        {
            son = x*2;
            if(x*2+1 <= size && H[2*x] > H[2*x+1])
                son = 2*x +1;
            if(H[son] >= H[x])
                son = 0;
        }
        if(son)
        {
            swap(pos[inv[x]],pos[inv[son]]);
            swap(inv[x],inv[son]);
            x = son;
        }
    }
    while(son);
}
void percolate(int x)
{
    while( x>1 && H[x/2] > H[x])
    {
        swap(pos[inv[x/2]],pos[inv[x]]);
        swap(inv[x/2],inv[x]);
        x = x/2;
    }
}
void push(int val)
{
    H[++size] = val;
    percolate(size);
}
void pop(int x)
{
    H[x] = H[size];
    size--;
    sift(x);
}
int main()
{
    int n,op,x;
    cin>>n;
    while(n--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            pos[++cnt] = size + 1;
            inv[size+1] = cnt;
            push(x);
        }
        else if(op==2)
        {
            cin>>x;
            pop(pos[x]);
        }
        else
        {
            cout<<H[1]<<'\n';
        }

    }
    return 0;
}
