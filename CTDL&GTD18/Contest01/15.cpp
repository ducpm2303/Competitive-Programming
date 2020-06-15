//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
string s;
int x;
void input(){
    cin >> x >> s;
}
void solve(){
    cout << x << ' ';
    int i = s.length() - 2;
    while(s[i] >= s[i+1] && i >= 0 ) i--;
    if(i == -1){
        cout << "BIGGEST" << endl;
        return;
    }
    int j = s.size()-1;
    while(j >=0 && s[j] <= s[i]) j--;
    swap(s[i],s[j]);
    for(int t = 0; t <=i; t++) cout << s[t];
    for(int t = s.size()-1; t> i; t--) cout << s[t];
    cout << endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();int t=1; 
    cin>>t; cin.ignore();
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD