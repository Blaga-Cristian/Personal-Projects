#include <iostream>

using namespace std;

int main()
{
    int p1, p2;
    cin >> p1 >> p2;

    for(int cif1 = 9; cif1 >= 1; --cif1)
        if(p1 % cif1 == 0 && p1 / cif1 <= 9)
            for(int mij = 9; mij >= 0; --mij)
                for(int cif2 = 9; cif2 >= 1; --cif2)
                    if(p2 % cif2 == 0 && p2 / cif2 <= 9)
                        cout << cif1 << p1 / cif1 << mij << mij << mij << cif2 << p2 / cif2 << endl;
    return 0;
}
