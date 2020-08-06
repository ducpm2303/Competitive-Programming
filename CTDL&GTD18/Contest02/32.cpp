//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
string s;
set < string > res;
int _div;
void input(){
    cin >> s;
    res.clear();
}
string isResult(string a){
    stack < char > st;
    string res = "";
    for(int i = 0 ; i < a.length() ; i++){
        if ( a[i] != '*') res += a[i];
        if ( a[i] == ')' || a[i] == '(' ){
            if(!st.empty() && st.top() == '(' && a[i] == ')')
                st.pop();
            else st.push(a[i]); 
        }
    }
    if(st.size() == 0 ) return res;
    return "*";
}
void Try(int i , int d){
    if ( d == 0){
        //cout << s << endl;
        string tmp = isResult(s);
        if ( tmp != "*") res.insert(tmp);
        return;
    } 
    for(int j = i + 1 ; j < s.length() ; j++){
        if(s[j] == ')' || s[j] == '('){
            char x = s[j];
            s[j] = '*';
            Try(j,d-1);
            s[j] = x;
        }
    }
}
void solve(){
    stack < char > st;
    int cnt = 0 , len = s.length();
    for(int i = 0 ; i < s.length() ; i++){
        if ( s[i] == ')' || s[i] == '(' ){
            if(!st.empty() && st.top() == '(' && s[i] == ')')
                st.pop();
            else st.push(s[i]); 
        }
        else cnt ++;
    }
    _div = st.size();
    if( (cnt == 1 && _div ==len- 1) || _div == len){
        cout << -1 << '\n';
        return ;
    }
    Try(-1,_div);
    set <string>::iterator pos;  
    for(pos = res.begin() ; pos != res.end() ; pos++)
        cout << *pos << ' ';
    cout << '\n';
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();
    int t=1; cin>>t;
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
 