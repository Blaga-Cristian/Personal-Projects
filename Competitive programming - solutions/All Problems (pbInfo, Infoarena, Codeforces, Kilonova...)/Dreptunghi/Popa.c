/** George Chichirim, University of Oxford
  * 100 points
  */
#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

struct retType {
    char type;
    int offset;
    int cnt;
    string s1, s2;
};

string sir;
int din[355];
int pos = 0, cntDrept = 0, cntStr = 1, lenH = 0, lenV = 0;

int parseInt() {
    int s = 0;
    while (pos < sir.size() && '0' <= sir[pos] && sir[pos] <= '9') {
        s = s * 10 + sir[pos] - '0';
        pos++;
    }
    return s;
}

retType solve(int h, int v) {
    char currType = sir[pos];
    pos++;
    if (currType == '*') {
        cntDrept++;
        lenH = max(lenH, h + 1);
        lenV = max(lenV, v + 1);
        return {'*', 0, 0, "", "*"};
    }
    int k = parseInt();
    retType ret = {currType, k, 1, "", ""};

    retType aux1 = solve(h, v);
    if (aux1.type == currType) {
        ret.cnt += aux1.cnt;
        ret.s1 += aux1.s1;
        ret.s1 += currType;
        ret.s1 += to_string(k - aux1.offset);
        ret.s1 += aux1.s2;
    } else {
        cntStr = (1LL * cntStr * din[aux1.cnt]) % mod;
        ret.s1 += currType;
        ret.s1 += to_string(k);
        ret.s1 += aux1.s1 + aux1.s2;
    }

    int newH = h, newV = v;
    if (currType == 'H') newH += k;
    else newV += k;
    retType aux2 = solve(newH, newV);
    if (aux2.type == currType) {
        ret.cnt += aux2.cnt;
        ret.offset += aux2.offset;
        ret.s1 += aux2.s1;
        ret.s2 += aux2.s2;
    } else {
        cntStr = (1LL * cntStr * din[aux2.cnt]) % mod;
        ret.s2 += aux2.s1 + aux2.s2;
    }

    return ret;
}

int main() {
    // ifstream cin("dreptunghi.in");
    // ofstream cout("dreptunghi.out");
    int type;
    cin >> type;
    assert(1 <= type && type <= 4);
    cin >> sir;
    assert(0 < sir.size() && sir.size() < 350);
    din[0] = din[1] = 1;
    for (int i = 2; i <= 350; i++)
        for (int j = 0; j < i; j++)
            din[i] = (din[i] + 1LL * din[j] * din[i - j - 1]) % mod;
    retType aux = solve(0, 0);
    cntStr = (1LL * cntStr * din[aux.cnt]) % mod;
    if (type == 1) {
        cout << cntDrept << "\n";
    } else if (type == 2) {
        cout << lenH << " " << lenV << "\n";
    } else if (type == 3) {
        cout << cntStr << "\n";
    } else {
        cout << aux.s1 + aux.s2 << "\n";
    }
    return 0;
}
