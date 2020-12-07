/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 5E6;
const int BASE = 13;
 
int hashT[MAX + 5];
int pw[MAX + 5];
int p, q;
string s;
int gethashT(int i, int j) {
	return hashT[j] - hashT[i - 1] * pw[j - i + 1];
}
void Input(){
    cin >> p >> q;
    cin >> s;
}

void Solve(){
    int _div = p / q;
    string t;
    if (_div == 0) t.push_back('0');
    else {
        while (_div) {
            t.push_back(_div % 10 + 48);
            _div /= 10;
        }
    } 
    reverse(t.begin(),t.end());
    int r = p % q;
    for (int i = 0 ; i < MAX - t.length(); i++) {
        r *= 10;
        t.push_back(r / q + 48);
        r %= q;
    }
    int n = s.length();
    int m = t.length();
    s.insert(0, " ");
    t.insert(0, " ");
    //cout << s << '\n';
    int hashS = 0;
    for (int i = 1 ; i <= n; i++) {
        hashS = hashS * BASE + s[i];
    }
    pw[0] = 1;
    for (int i = 1 ; i <= m; i++) {
        pw[i] = pw[i - 1] * BASE;
        hashT[i] = hashT[i - 1] * BASE + t[i];
    }
    bool bl = false;
    for (int i = 1 ; i <= m - n + 1; i++) {
        if (hashS == gethashT(i, i + n - 1)) {
            bl = true;
            cout << i;
            break;
        }
    }
    if (!bl) cout << 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
