/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int Precedence(char x){
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}
void Input(){
    getline(cin,s);
}
void Solve(){
    string postfix = "";
    stack <char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ') continue;
        if('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z'){
            postfix += s[i];
        }else{
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')'){
                while(st.top() != '('){
                    res += st.top();
                    st.pop();
                } 
            }else{
                while(Precedence(s[i]) <= Precedence(st.top()) && !st.empty()){
                    
                }
            }
        }
        
        
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
