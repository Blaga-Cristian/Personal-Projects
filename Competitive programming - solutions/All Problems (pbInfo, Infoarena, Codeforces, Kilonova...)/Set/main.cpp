#include <fstream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

ifstream cin("set.in");
ofstream cout("set.out");

set <int> a;

int main(){

    std::set<int>::iterator itlow,itup;
    int n;
    cin >> n;
    int cerinta,x,y,val;
    for(int i = 1 ; i <= n ; ++i){

        cin >> cerinta;
        if(cerinta == 1){
            cin >> val;
            a.insert(val);

        }
        else if(cerinta == 2){
            cin >> val;
            itlow = a.lower_bound(val);
            if(*itlow >= val)
                cout << *itlow << '\n';
            else
                cout << -1 << '\n';
        }
        else{
            cin >> x >> y;
            itlow = a.lower_bound(x);
            itup = a.lower_bound(y);
            a.erase(itlow,itup);
        }


    }
    /*
    std::set<int>::iterator it;
    for (it = a.begin() ; it != a.end(); ++it)
        cout  << *it;

    */



    return 0;
}
