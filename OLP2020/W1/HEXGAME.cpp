/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> b;
vector<int> res;
void Input(){
    cin >> n;
    b.resize(n*(n+1)/2 + 1,0);
    res.resize(n*(n+1)/2 + 1,0);
    for(int i = 1; i <= n*(n+1)/2; i++){
        cin >> b[i];
        res[i] = i;
    }
}
vector<int> Rotate(int i, int j, int k, vector<int> a){
    int tmp = a[i]; a[i] = a[j];
    a[j] = a[k], a[k] = tmp;
    return a;
}
vector<int> rightShift(int st, vector<int> a){
    if(st == 2){
        swap(a[2],a[3]);
    }else if(st == 4){
        int tmp = a[6]; a[6] = a[5];
        a[5] = a[4], a[4] = tmp;
    }else if(st == 7){
        int tmp = a[10]; a[10] = a[9];
        a[9] = a[8], a[8] = a[7], a[7] = tmp;
    }
    return a;
}
void Case2(){
    if(b[1] == 1) cout << 0;
    else cout << 1;
}
void Case3(){
    map<vector<int>,int> dist1,dist2;
    queue<vector<int>> q; q.push(b);
    while(!q.empty()){
        vector<int> a = q.front(); 
        int d = dist1[a];
        if(a == b){
            cout << d;
            return;
        }
        vector<int> row2 = rightShift(2,a);
        

    }
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
