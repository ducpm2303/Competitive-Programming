//Code By PMD
#include<bits/stdc++.h>
using namespace std;
/*
    mang danh dau.
*/
const int maxN = 1e5+5;
int n;
int a[maxN];
void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}

void solve(){
    /*
    
    */
    int b[maxN] = {0};
    for(int i = 0 ; i < n ; i++)
       b[a[i]] = 1;
    int l = *min_element(a,a+n); // min cua a
    int r = *max_element(a,a+n); // max cua a
    int res = 0;
    for(int i = l + 1 ; i < r ; i++)
        if ( b[i] == 0 ) res ++;
    cout << res << endl;
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
 