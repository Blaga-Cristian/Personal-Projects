#include<bits/stdc++.h>
using namespace std; typedef long long ll; int main() {

string str; cin>>str; int n=str.length(); sort(str.begin(),str.end()); string s="";string temp=""; string o="";int c=1,cc=0; for(int i=0;i<n;i++) { if(i==n-1) { if(c%2==0) s.insert((s.length()/2),str.substr(cc,c)); else o+=str.substr(cc,c); }

else if(str.at(i)==str.at(i+1))
c++;
else{


    if(c%2==0)
    s.insert((s.length()/2),str.substr(cc,c));
    else
    o+=str.substr(cc,c);
    cc+=c;c=1;

}
} s.insert((s.length()/2),o); temp=s; reverse(temp.begin(),temp.end()); if(temp==s) cout<<s; else cout<<"NO SOLUTION"<<endl;

}
