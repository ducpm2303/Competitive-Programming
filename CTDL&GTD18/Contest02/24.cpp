#include<bits/stdc++.h>
using namespace std;
int n,k;
vector < int > a;
vector < vector <int> > res;
void input(){
    cin >> n >> k ;
    a.resize(n); res.clear();
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
void Try(int i , int s , vector<int> mv){
    if ( s == k ){ // nếu s = k đẩy vector hiện tại vào res
        res.push_back(mv);
        return;
    }
    int j = i + 1;
    while((s + a[j] ) <= k && j < n){ // điêu kiện s + a[j] <= k và j < n
        mv.push_back(a[j]); // thử trường hợp a[j]
        Try(j,s+a[j],mv); // Gọi đệ quy.
        mv.pop_back(); // sau khi thử xong xoá a[j] khỏi cuối vector
        j++;
    }
}
void solve(){
    sort(a.begin(),a.end()); 
    vector < int > move;
    Try(-1,0,move);
    if( res.size() == 0 ){ 
        cout << -1 << '\n';
        return;
    }
    for(int i = 0 ; i < res.size() ; i++){
        cout << '[';
        for(int j = 0 ; j < res[i].size() ; j++){
            cout << res[i][j];
            if( j == res[i].size() - 1) cout << "]";
            cout << ' ';
        }
    }
    cout << '\n';
}
int main(){
    int t=1; cin>>t;
    while(t--){ input();solve();}
    return 0;
}