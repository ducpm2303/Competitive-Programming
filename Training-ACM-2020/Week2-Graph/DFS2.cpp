/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Duyet_canh_cau_DFS(int a[][10]){
    int res = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            if( a[i][j] == 1){
                a[i][j] = a[j][i] = 0;
                reset();
                int cnt = 0;
                DFS(1,cnt);
                if(cnt != n) res++;
                a[i][j] = a[j][i] = 1;           
            }
        }
    }
    return res;
}
void Input(){

}
void Solve(){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
