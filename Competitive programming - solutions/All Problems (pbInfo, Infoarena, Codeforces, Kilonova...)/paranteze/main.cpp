#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
ifstream cin("paranteze1.in");
ofstream cout("paranteze1.out");
int n;
int main()
{
    int maxi=-13;
    stack<int> a;
    char s[256];
    cin.get(s,255);
    cin.get();
    for(int i=0;i<strlen(s);++i)
    {
        if(s[i]=='(')a.push(1);
        else a.pop();
        int val=a.size();
        if(val>maxi)maxi=val;
    }
    cout<<maxi;
    return 0;
}
