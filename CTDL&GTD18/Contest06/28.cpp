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
    cout << "Buoc " << 0 << ": " << a[0] << '\n';
    int step = 1;
    for(int i = 1 ; i < n  ; i++ , step++){
        int tmp = a[i];
        int j = i - 1;
        while( a[j] > tmp && j >= 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        cout << "Buoc " << step << ": " ;
        for(int i = 0 ; i <= step ; i++)
            cout << a[i] << ' ';
        cout << '\n';
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
