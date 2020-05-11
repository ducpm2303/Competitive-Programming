//Code By PMD
#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep. + tham lam
*/
const int maxN = 1e5+5;
pair<int,int> a[maxN];
int n,x;
bool cmp(pair<int,int> a, pair<int,int> b){
    if (abs(a.first-x) == abs(b.first-x)) return a.second < b.second;
    return ( abs(a.first-x) < abs(b.first-x)  );
}
void input(){
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
        
}
void solve(){
    sort(a,a+n,cmp);
    for(int i = 0 ; i < n ; i++)
        cout << a[i].first << ' ';
    cout << endl;
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
 