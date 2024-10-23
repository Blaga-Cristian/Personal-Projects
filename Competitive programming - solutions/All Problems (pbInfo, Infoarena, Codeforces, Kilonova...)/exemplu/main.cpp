#include <fstream>

using namespace std;
ifstream fin("32.in");
ofstream fout("32.out");

int main()
{
    int a,s=0;
    while(fin>>a)
    {
        s=s+a;
    }
    fout<<s;
    return 0;
}
