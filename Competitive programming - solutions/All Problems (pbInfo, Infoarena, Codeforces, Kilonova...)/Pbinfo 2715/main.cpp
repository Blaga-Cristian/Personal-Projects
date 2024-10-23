#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    while(cin.get(c))
    {
        if(c!=' ' && c!=0)
        {
            if(c >= 'a')
                c = (c - 'a' + 13) % 26 + 'a';
            else
                c = (c - 'A' + 13) % 26 + 'A';
        }
        cout<<c;
    }
    return 0;
}
