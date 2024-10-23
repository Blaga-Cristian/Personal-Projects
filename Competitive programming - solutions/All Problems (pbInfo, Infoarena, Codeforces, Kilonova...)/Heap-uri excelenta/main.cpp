#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream fin("heapuri.in");
ofstream fout("heapuri.out");

class Heap
{
    using VI = vector<int>;
public:
    Heap() : idx(0), nH(0), H(VI(1)), P(VI(1)), D(VI(1))
    {}
    Heap(int sz) : idx(0), nH(0), H(VI(sz + 1)), P(VI(sz + 1)), D(VI(sz + 1))
    {}

    void up(int s) /// ia index-ul nodului in H ca parametru
    {
        for(int p = s / 2; p != 0 && D[H[p]] > D[H[s]]; s = p, p /= 2)
            Swap(p, s);
    }

    void down(int p) /// ia index-ul nodului in H ca parametru
    {
        for(int s = 2 * p; s <= nH;)
        {
            if(s + 1 <= nH && D[H[s + 1]] < D[H[s]])
                s ++;

            if(D[H[p]] > D[H[s]])
            {
                Swap(s, p);
                p = s;
                s *= 2;
            }
            else
                break;
        }
    }

    void push(int value)
    {
        H[++nH] = ++idx, P[idx] = nH, D[idx] = value;
        up(nH);
    }

    void pop(int nod = -1)
    {
        int x;
        if(nod == -1)
            x = 1;
        else
            x = P[nod];

        Swap(x, nH --);

        up(x);
        down(x);
    }


    int top() const noexcept
    {
        return D[H[1]];
    }


    bool empty() const noexcept
    {
        return nH <= 0;
    }


private:
    void Swap(int a, int b) /// ia indexii heap-ului, H are ca valori nr nodului
    {
        swap(H[a], H[b]);
        P[H[a]] = a;
        P[H[b]] = b;
    }

    int idx;
    int nH;
    VI H, P, D;
    ///P[i] = pozitia pe care se afla nodul i in H
    ///H[i] = nodul cu valoarea de pe poz i in heap
    ///D[i] = valoarea nodului i
};

int n, x, op;
Heap heap;

int main()
{
    fin >> n;

    Heap heap(n + 9);

    while(n --)
    {
        fin >> op;
        if(op == 1)
        {
            fin >> x;
            heap.push(x);
        }
        else if(op == 2)
        {
            fin >> x;
            heap.pop(x);
        }
        else if(op == 3)
        {
            fout << heap.top() << '\n';
        }
    }
    return 0;
}
