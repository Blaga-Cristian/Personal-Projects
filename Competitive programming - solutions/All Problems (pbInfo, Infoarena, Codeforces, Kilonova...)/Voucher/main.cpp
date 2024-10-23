/* Alg lui Dijkstra
 * Complexitate: O(n^2)
 * Det distanta minima de la un nod ales drept sursa
 * la celelalte noduri din graf.
 *
 */
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

ifstream fin("vacanta2020.in");
ofstream fout("vacanta2020.out");

const int Inf = 0x3f3f3f3f;
using VI  = vector<int>;
using PI  = pair<int, int>;
using VP  = vector<PI>;
using VVP = vector<VP>;

VVP G;
VI d;
VI t;
int n, m,k;

void ReadGraph();
void Dijkstra(int x, VI& d); // x = nodul sursas
void WriteDist(VI& d);

int main()
{
	ReadGraph();
	Dijkstra(1, d);
	WriteDist(d);

	return 0;
}

void Dijkstra(int x, VI& d) // O(n * log2(m))
{
	priority_queue<PI, vector<PI>, greater<PI>> Q;
	d = VI(n + 1, Inf);
	d[x] = 0;
	Q.emplace(0, x);

	while (!Q.empty())
	{
		// Structured Binding - C++17
		int dx,x;
		dx = Q.top().first;
		x = Q.top().second;
		Q.pop();

		if (dx > d[x]) // daca x iese din coada pentru a doua oara
			continue;

		for (auto p : G[x])
		{
			int y,w;
			y = p.first;
			w = p.second;
			if (d[y] > d[x] + w)
			{
				d[y] = d[x] + w;
				Q.emplace(d[y], y);
			}
		}
	}
}

void WriteDist(VI& d)
{
	for (int i = 2; i <= n; ++i)
		if (d[i] != Inf)
			fout << d[i] << ' ';
		else
			fout << "0 ";
}

void ReadGraph()
{
	fin >> n >> m >> k ;
	G = VVP(n + 1); // G[0], G[1]
    t = VI(n+1);
	int x, y, w;
	while (m--)
	{
		fin >> x >> y >> w;
	//	G[x].push_back({y, w});
	//	G[y].push_back({x, w});
		G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
	}
}

