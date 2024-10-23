#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;
unordered_set<int>frecv;
unordered_set<int>::iterator p;
int v[26];
char s[10010];
bool ok()
{
    for(p=frecv.begin();p!=frecv.end();p++)if(v[*p]==0)return 0;
    return 1;
}
int main()
{
    int i=0,j=0,st,dr;
    char x;
    cin.get(s,10000);
    for(i=0;i<strlen(s);i++)frecv.insert(s[i]-'a');
    i=0;
    j=0;
    v[s[i]-'a']++;
    while(!ok())
    {
        i++;
        v[s[i]-'a']++;
    }
    v[s[j]-'a']--;
    while(ok())
    {
        j++;
        v[s[j]-'a']--;
    }
    v[s[j]-'a']++;
    st=j+1;
    v[s[j]-'a']--;
    dr=i+1;
    v[s[i+1]-'a']++;
    while(dr<strlen(s))
    {
        if(ok())
        {
            while(ok())
            {
                v[s[st]-'a']--;
                st++;
            }
            st--;
            v[s[st]-'a']++;
        }
        if(dr==strlen(s)-1)break;
        dr++;
        v[s[dr]-'a']++;
        v[s[st]-'a']--;
        st++;
    }
    cout<<dr-st+1;
    return 0;
}
