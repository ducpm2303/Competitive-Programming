/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<string>dp;
string add(string a, string b){
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
 
string mul(string a, string b){
    string res="";
    int n=a.length(); int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--){
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
void sieve(){
    dp.resize(105,"0");
    dp[0] = dp[1]= "1";
    for(int i = 2 ; i <= 100 ; i++){
        int mid = i/2 ;
        for(int j = 0 ; j < mid ; j++){
            dp[i] = add(dp[i],mul(dp[j],dp[i-j-1]));
        }
        dp[i] = mul(dp[i],"2");
        if(i%2) dp[i] = add(dp[i],mul(dp[i/2],dp[i/2]));
    }
}
void Input(){
    cin >> n ; 
}
void Solve(){
    cout << dp[n] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    sieve();
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
