/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set < pair < int, int > > s;
void Input(){
   
}
void Solve(){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1 ; i <= n; i++) {
        string str;
        getline(cin, str);
        str += ' ';
        int val = 0;
        for (int j = 0 ; j < str.length(); j++) {
            if (str[j] == ' ' ) {
                s.insert(make_pair(min(i, val), max(i, val)));
                val = 0;
            } 
            else val = val * 10 + (str[j] - '0');
        }   
    }
    for (auto it : s) {
        cout << it.first << " " << it.second << endl;
    }
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
