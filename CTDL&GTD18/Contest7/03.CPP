/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    getline(cin,s);
}
void Solve(){
    s = ' ' + s + ' ';
    vector <string> tmp;
    vector <int> pos;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == ' ') pos.push_back(i);
    }
    for(int i = 0; i < pos.size() - 1; ++i){
        if(pos[i] + 1 == pos[i+1]) continue;
        //cout << pos[i] + 1 << ' ' << pos[i+1]-pos[i]-1 << '\n';
        string z = s.substr(pos[i]+1,pos[i+1]-pos[i]-1);
        reverse(z.begin(),z.end());
        cout << z << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t; cin.ignore();
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
