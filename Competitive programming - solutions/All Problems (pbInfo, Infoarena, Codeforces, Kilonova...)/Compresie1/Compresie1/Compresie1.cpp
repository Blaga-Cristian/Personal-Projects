// Compresie1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("compresie.in");
ofstream cout("compresie.out");
char s[1000002], matrice[1001][1001];
void decomprimare(char* s,int size,int x,int y)
{
    int i,nr=1,k,j;
    for (i = 1; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            if (s[i] != '*')
            {

            }
            else
            {
                
            }
        }
    }
}
int main()
{
    cin.get(s, 1000000);
    if (s[0] != '*')cout << 1 << endl << s[0];
    else
    {
        char* p;
        int nr = 0;
        p = s;
        while (strchr(p, '*') != NULL)
        {
            p =strchr(p, '*') + 1;
            nr++;
        }
        cout << nr<<endl;
        decomprimare(s, strlen(s) - 1, 0, 0);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
