#include <bits/stdc++.h>
using namespace std;
ifstream fin("palindrom.in");
ofstream fout("palindrom.out");
int main()
{
    int n;
    fin >> n;
    for(int i = 0 ; i < n ; ++i)
    {
        char ch[101];
        fin >> ch;
        int m = 0;
        while(ch[m]!='\0')
            m++;
        m--;
        int j = 0;
        bool adev=true;
        while(ch[j]!='\0')
        {
            if(ch[j]!=ch[m-j])
                adev=false;
            j++;
        }
        if(adev)
            fout << 1 << endl;
        else
            fout << 0 << endl;
    }
    return 0;
}
