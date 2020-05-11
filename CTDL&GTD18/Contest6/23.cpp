#include<iostream>
using namespace std;
typedef long long i64;
/*
    mang danh dau xuat hien danh dau 1 , khong xuat hien danh dau 0;
*/
const int maxN = 1e7+5;
int a[maxN],b[maxN];
int n;
void input(){
    cin >> n ;
    for(int i = 0 ; i < n - 1; i++)
        cin >> a[i];
    for(int i = 1 ; i <= n ; i++)
        b[i] = 0;
}
void solve(){
    for(int i = 0 ; i < n - 1 ; i++)
        b[a[i]] = 1;  
    for(int i = 1 ; i <= n ; i++){
        if (b[i] == 0){
            cout << i << endl;
            break;
        }
    }

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