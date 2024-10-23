#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[255];
    char s[11][1000] = {"Cate grafuri neorientate cu 4 varfuri exista?",
    "Cate grafuri neorientate, distincte, cu 4 varfuri, se pot construi? Doua grafuri se considera distincte daca matricele lor de adiacenta sunt diferite.\n 24\n 4\n 4^6\n 2^6\n",
    "Care dintre urmatoarele afirmatii sunt corecte?\nIntr-un graf neorientat o muchie poate fi adiacenta cu un varf.\nIntr-un graf neorientat doua muchii pot fi adiacente.\nIntr-un graf neorientat o muchie poate fi incidenta cu un varf.\nIntr-un graf neorientat doua varfuri pot fi incidente.",
    "Intr-un graf orientat cu 7 noduri suma gradelor interioare ale tuturor nodurilor este egala cu 10. Care este valoarea sumei gradelor exterioare ale tuturor nodurilor?\n5\n20\n10\n15",
    "Cate noduri ale grafului orientat cu sase noduri numerotate de la 1 la 6 si urmatoarele arce: (1,5), (1,6), (2,1), (2,3), (3,1), (3,4), (4,3), (4,5), (5,4), (6,5) au gradul interior egal cu gradul exterior?",
    "Se considera graful orientat cu 6 noduri, numerotate de la 1 la 6, si arcele (1,2), (1,5), (1,6), (2,3), (4,3), (4,5), (6,5). Care este numarul minim de arce ce trebuie adaugate grafului astfel incat acesta sa contina cel putin un circuit elementar de lungime 4?",
    "Cate frunze are arborele cu radacina descris prin urmatorul vector ”de tati”: (6,5,5,2,0,3,3,3,8,7,7)?",
    "Se considera un arbore cu radacina in care doar 13 dintre nodurile arborelui au exact 2 descendenti directi (fii), restul nodurilor avand cel mult un descendent direct (fiu). Care este numarul frunzelor arborelui?",
    "Cati frati are nodul 1 din arborele cu radacina, cu 7 noduri, numerotate de la 1 la 7, avand urmatorul vector ”de tati”: (5,1,5,1,0,7,5)?"};
    char ans[11][100] = {"64","2^6","3","3","1","2","5","14","2"};
    for(int i=0;i<9;++i)
    {
        cout<<s[i]<<'\n';
        while(true)
        {
            cin.getline(a,255);
            if(strlen(a)==0)continue;
            if(strcmp(ans[i],a)==0)
            {
                cout<<"Corect\n";
                break;
            }
            else cout<<"Gresit\n";
        }
    }
    return 0;
}
