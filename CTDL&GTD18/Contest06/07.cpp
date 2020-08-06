//Code By PMD
#include<iostream>
#include<algorithm>
using namespace std;
/*
*/
const int maxN = 1e5+5;
int a[maxN],b[maxN],n;

void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
    	cin >> a[i];
    	b[i] = a[i];
	}
 
}
void solve(){
	sort(b,b+n);
    int l = 0 , r = n - 1;
    /*
    A 1 7 4 3 2 9
    B 1 2 3 4 7 9
    */
    while (l < n  && a[l] == b[l]) l++;
    while (r >= 0 && a[r] == b[r]) r--;
    cout << l + 1 << ' ' << max(r, l) + 1<< '\n'; 
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
 
