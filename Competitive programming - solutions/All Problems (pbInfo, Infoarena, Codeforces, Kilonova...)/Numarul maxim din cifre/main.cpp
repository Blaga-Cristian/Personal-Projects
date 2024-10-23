#include <fstream>

using namespace std;

const int NMAX = 1e6 + 2;

ifstream fin("eliminare.in");
ofstream fout("eliminare.out");

char a[NMAX], x;
int n, m, maxi[NMAX];

int main()
{
    n = 0;
    fin.get(x);
    while (isdigit(x)) /// citim numarul si il preclucram ca si un sir de caractere
    {
        a[++n] = x;
        fin.get(x);
    }

    fin >> m;

    /// cu siguranta stim ca exista un numar care se poate forma din ultimele n - m cifre, asa ca vom cauta in intervalul [1, n - m]
    /// cel mai mare numar care se poate forma cu cifrele acestea
    /// dupa ce gasim acest numar, vom schimba intervalul de cautare, capatul din stanga devenind n - m + 1, iar cel din dreapta devenind n - m + 1 + x,
    /// unde x este numarul de cifre al celui mai mare numar care a fost determinat in intervalul anterior
    /// repetam acest procedeu cat timp capatul din stanga e mai mic decat capatul din dreapta
    /// in momentul in care acest lucru nu se mai intampla, vom afisa toate cifrele care au ramas pana la final

    int left_index = 1, right_index = m, deleted = n - m;;

    while (right_index <= n && deleted)
    {
        maxi[right_index] = right_index;

        for (int i = right_index - 1; i >= left_index; i--)
        {
            maxi[i] = i;
            if (a[maxi[i + 1]] > a[maxi[i]])
                maxi[i] = maxi[i + 1];
        }

        int new_left_index = left_index, new_right_index = right_index;

        while (a[maxi[new_left_index]] >= a[right_index + 1] )
        {
            deleted--;
            new_right_index++;
            fout << a[maxi[new_left_index]];
            new_left_index = maxi[new_left_index] + 1;
        }

        if (right_index == new_right_index)
            {
                for (int i = right_index + 1; i <= n; i++)
                    fout << a[i];
                return 0;
            }
        else
        {
            left_index = right_index + 1;
            right_index = new_right_index;
        }
    }

   return 0;
}
