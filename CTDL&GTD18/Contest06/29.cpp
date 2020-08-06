/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
void Input(){
    cin >> n ; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
void Solve(){
    /*
    4
    5 3 2 7
    3 2 5 7
    2 3 5 7
    
    */
    int step = 1;
    for(int i = 0 ; i < n; i++){
        bool ok = false;
        for(int j = 0 ; j < n - 1; j++){
            if(a[j] > a[j+1]){
                ok = true;
                swap(a[j],a[j+1]);
            }
        }
        if(ok == false) break;
        cout << "Buoc " << step << ": ";
        for(int i = 0 ; i < n ; i++) cout << a[i] << ' ';
        cout << '\n';
        step++;
    }
    
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
