/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
stack<int> st;
vector<int> x(20);
vector<pair<int,int>> a;
set <string> res;

void Input(){
    getline(cin,s);
}

void Update(){
    string tmp = "";
    int ok[s.length()+1] = {0} ;
    for(int i = 0; i < a.size(); i++)
        ok[a[i].first] = ok[a[i].second] = x[i];
    for(int i = 0; i < s.length(); i++)
        if(ok[i] == 0) tmp += s[i];
    res.insert(tmp);
}
void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == a.size() - 1) Update();
        else Try(i+1);
    }
}
void Solve(){
    //cout << s << '\n';
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')'){
            a.push_back({st.top(),i});
            st.pop();
        }
    }
    Try(0);
    res.erase(res.begin());
    for(auto z : res) cout << z << '\n';

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
