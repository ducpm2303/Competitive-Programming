//Code By PMD
#include<iostream>
#include<algorithm>
using namespace std;
/*
    dung 2 mang danh dau .
    phan tu nao xuat hien trong ca hai mang thi cho vao mang giao ,
    xuat hien o mot trong hai bang thi cho vao mang hop
*/
const int maxN = 1e5+5;
int a[maxN],b[maxN],n,m;
int da[maxN],db[maxN];

void input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }
    for(int i = 0 ; i <= 1e5 ; i++)
        da[i] = db[i] = 0;
}
void solve(){
    for(int i = 0 ; i < n ; i++) da[a[i]] = 1;
    for(int i = 0 ; i < m ; i++) db[b[i]] = 1;
    for(int i = 0 ; i <= 1e5 ; i++)
        if( da[i] == 1 || db[i] == 1) cout << i << ' ';
    cout << endl;
    for(int i = 0 ; i <= 1e5 ; i++)
        if(da[i] == 1 && db[i] == 1) cout << i << ' ';
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
 