//Code By PMD
#include<bits/stdc++.h>
using namespace std;
/*
    nhap vao 1 string dem chu so cho nhanh.
    dem chu so + sap xep + tham lam.
*/
const int maxN = 1e7+4;
int n;
string a[maxN];
void input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}

void solve(){
    int cnt[10] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].length(); j++){
            int x = a[i][j] - '0';
            cnt[x]++;
        }
    }
    for(int i = 0; i < 10; i++){
        if(cnt[i] != 0) cout << i << ' ';
    }
    cout << '\n';
}
int main(){
    int t=1; 
    cin>>t; 
    while(t--){ 
        input();
        solve();
    }
    return 0;
}
//Code By PMD
 