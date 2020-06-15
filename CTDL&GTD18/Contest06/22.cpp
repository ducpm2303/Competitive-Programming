#include<iostream>
using namespace std;
typedef long long i64;
/*
    mang danh dau xuat hien danh dau 1 , khong xuat hien danh dau -1;
*/
const int maxN = 1e6+5;
int a[maxN],b[maxN];
int n,x;
void input(){
    cin >> n >> x ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i <= 1e6 ; i++)
        b[i] = -1;
}
void solve(){
    for(int i = 0 ; i < n ; i++)
        b[a[i]] = 1;  
    cout << b[x] << endl;

}
int main(){
	int t = 1;
	cin >> t; 
	while(t--){
        input() ; 
        solve();
    }
	return 0;
}