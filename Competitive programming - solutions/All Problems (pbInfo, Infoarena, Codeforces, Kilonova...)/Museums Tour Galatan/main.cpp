// https://codeforces.com/contest/1137/problem/C
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VS = vector<string>;

const int Inf = 0x3f3f3f3f;

int N, M, D;
VVI G0, G;			// G0 -> graful intial, al muzeelor, G -> grfaul creat in functia BuildGraph
VVI gc;				// gc -> graful comp. tare-conexe din graful G
VS open;			// open[i][j] = 1 <=> muzeul i e deschis in ziua j
VI scc;				// scc[i] = comp. tare-conexa din care face parte nodul i
VI m;				// m[i] = nr. de muzee distincte deschise in componenta tare-conexa i
int nrc;
VI seen;

stack<int> st;
VI lv, low;
VB inStack;
int _lv;

void ReadData();
void Solve();
void BuildNewGraph();
inline void Tarjan(int node);
void TopologicalSort(int node);
//void WriteGraph(VVI& G);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);	// optimizari la citire

	ReadData();
	Solve();

	return 0;
}

void ReadData()					// citesc graful initial care stabileste legaturile intre muzee
{
	cin >> N >> M >> D;

	G0 = VVI(N);
	int x, y;
	while (M--)
	{
		cin >> x >> y;
		--x; --y;
		G0[x].push_back(y);
	}

	open = VS(N);
	for (int i = 0; i < N; ++i)
		cin >> open[i];					// open[i][j] = 1 <=> muzeul i e deschis in ziua j
}

void Solve()
{
	BuildNewGraph();				// creez noul graf

	lv = low = VI(N * D);
	inStack = VB(N * D);
	scc = VI(N * D, -1);
	seen = VI(N);

	Tarjan(0);						// calzulez comp. tare-conexe (ma intereseaza doar acelea in care pot ajunge din nodul 0 pt. ca eu ponesc din nodul 0)

	//for (int i = 0; i < N * D; ++i)
	//	if (!lv[i])
	//		Tarjan(i);

	gc = VVI(nrc);
	for (int i = 0; i < N * D; ++i)			// creez alt graf, al componentelor tare-conexe (graf orientat aciclic)
		for (const int& v : G[i])
			if (scc[i] != scc[v] && scc[i] != -1 && scc[v] != -1)
				gc[scc[i]].push_back(scc[v]);

	int ans{0};

	lv = VI(nrc);
	for (int i = 0; i < nrc; ++i)			// sortez topologic acest graf
		if (!lv[i])
			TopologicalSort(i);

	VI cost(nrc + 1, -Inf);					// trebuie sa gasesc un cost maxim catre oricare nod, porning din nodul
											// al carei componente tare-conexe contine nodul 0 (nodul de plecare)
	cost[scc[0]] = m[scc[0]];				// nu am costuri pe muchii, ci am costuri pe noduri, costurile fiind
											// in sirul m in care retin cate muzee vizitez parcurgand o comp. tare-conexa (adica un nod din graful gc)
	while (!st.empty())
	{
		int node = st.top();
		st.pop();

		if (cost[node] == -Inf)
			continue;

		for (const int& v : gc[node])
			cost[v] = max(cost[v], cost[node] + m[v]);
	}

	for (int i = 0; i < nrc; ++i)
		ans = max(ans, cost[i]);

	cout << ans;
}

void BuildNewGraph()
{
	G = VVI(N * D);							// pentru fiecare nod din graful initial, creez D alte noduri, unde D e numarul de zile
	for (int i = 0; i < N * D; ++i)			// deci nodurile din noul graf sunt de forma (nod; ziua din saptamana) in noul graf G (graful initial e G0)
	{										// Un nod i din noul graf contine urmatoarele informatii: sunt in orasul i % N si in ziua i / N
		for (const int& v : G0[i % N])									// orice muchie (u; v) care exista in graful initial acum va deveni o muchie de la
			G[i].push_back( (((i / N + 1) * N) + v) % (N * D) );		// nodul u din ziua x la nodul v din ziua x + 1 (imi ia o zi sa parcurg muchia u->v)
	}
}

inline void Tarjan(int node)
{
	lv[node] = low[node] = ++_lv;
	st.push(node); inStack[node] = true;

	for (const int& v : G[node])
	{
		if (!lv[v])
		{
			Tarjan(v);
			low[node] = min(low[node], low[v]);
		}
		else
			if (inStack[v])
				low[node] = min(low[node], low[v]);
	}

	if (lv[node] <= low[node])
	{
		int x;
		m.push_back(0);

		do{
			x = st.top();
			st.pop(); inStack[x] = false;
			scc[x] = nrc;

			if (seen[x % N] != nrc + 1 && open[x % N][x / N] == '1')		// m[i] = nr. de muzee distincte deschise in componenta tare-conexa i
			{																// odata cu componentele tare-conexe creez si vecotrul m, DAR trebuie sa am
				seen[x % N] = nrc + 1;										// grija sa nu pun un acelasi muzeu de doua ori, pentru ca doua noduri diferite
				++m[nrc];													// din graful G pot indica catre acelasi muzeu, ata doar ca in zile diferite
			}																// deci seen[i] = am vizitat muzeul i in aceasta comp. tare-conexa?
		}while (x != node);

		++nrc;		// numarul de comp. tare-conexe
	}
}

void TopologicalSort(int node)		// sortare topologica
{
	lv[node] = 1;

	for (const int& v : gc[node])
		if (!lv[v])
			TopologicalSort(v);

	st.push(node);
}

/*void WriteGraph(VVI& G)
{
	ofstream cout("graf.out");
	cout << G.size() << '\n';
	for (size_t i = 0; i < G.size(); ++i)
	{
	//	cout << "Nodul " << i << " : ";
		for (const int& v : G[i])
			cout << i << ' ' << v << '\n';
		//cout << '\n';
	}
	cout << "\n\n";
	cout.close();
	//cin.get();
}
	*/
