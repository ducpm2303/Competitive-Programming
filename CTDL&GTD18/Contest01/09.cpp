/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100],n;
void Display(){
    cout << x[1];
    for(int i = 2; i <= n; i++){
        int a = x[i]^x[i-1];
        cout << a;
    }
    cout << ' ';
}
void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n){
            Display();
        }else{
            Try(i+1);
        }
    }
}
void Input(){
    cin >> n;
}

void Solve(){
    Try(1);
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
