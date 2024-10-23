#include <fstream>
#include <vector>
using namespace std;

ifstream fin("BECURI.IN");
ofstream fout("BECURI.OUT");

const int Inf = 1 << 30;

using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;

int n, P;

VVI a;   // a[x][i] = nr minim de taieturi ca sa avem un subarbore
         // cu rad in x cu i noduri
VVI G;
VI nr;   // nr[x] = greutatea subarborelui cu rad in x
VB v;
// nr minim de taieturi (cerinta)
int min_t = Inf;


void Citeste();
void Df(int x);

int main()
{
	Citeste();
	Df(1);

	fout << min_t;
}

void Df(int x)
{
	v[x] = true;
	a[x][1] = G[x].size();
	nr[x] = 1;

	for (const int& f : G[x])
	{
		if (v[f]) continue; // daca  NU e tata lui x
		Df(f); // a[f][1], a[f][2], ..., a[f][P]
		VI aux(a[x]);
		for (int i = 1; i <= P && i <= nr[x]; ++i) // nr de noduri in x
			for (int j = 1; i + j <= P && j <= nr[f]; ++j)
			{
				if (a[x][i] == Inf || a[f][j] == Inf) continue;

				if (a[x][i] + a[f][j] - 2 < aux[i + j])
					aux[i + j] = a[x][i] + a[f][j] - 2;
			}

		a[x] = aux;
		nr[x] += nr[f];
	}

	min_t = min(min_t, a[x][P]);
}

void Citeste()
{
	fin >> n >> P;
	G = VVI(n+1);
	a = VVI(n + 1, VI(P + 1, Inf));
	v = VB(n + 1);
	nr = VI(n + 1);
	int x, y;

	for (int i = 1; i < n; ++i)
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
}

