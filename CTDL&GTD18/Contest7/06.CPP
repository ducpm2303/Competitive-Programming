/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    getline(cin,s);
}
void Solve(){
    stack <char> st;
    for(int i = 0; i<s.length(); i++){
        if(s[i] != ')') st.push(s[i]);
        else{
            bool check = false;
            while(!st.empty()){
                char c = st.top();st.pop();
                if(c == '(') break;
                if(c == '+' || c == '-' || c == '/' || c == '*')
                    check = true;
            }
            if(check == false){
                cout << "Yes" << '\n';
                return;
            }
        }
    }
    cout << "No" << '\n';
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
