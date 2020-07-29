#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
int test = 1 , MULTI_TEST = 1; 
int n,k,sum = 0,cnt = 0;
vector < int > a; 
vector < int > vis; // mảng đánh dấu
void Input(){
    cin >> n >> k;
    a.resize(n); 
    vis.assign(n+1,0); // khởi tạo mảng đánh dấu tất cả bằng 0
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}
void Try(int i , int s, vector<int> id){
    if(cnt == k) return; // điều kiện dừng Try đang xét
    if (s == sum){
        // nếu s == sum thì đánh dấu những vị trí trong id lại và ko xét trong tập con nào nữa
        cnt ++;
        for(int z = 0 ; z < id.size() ; z++)
            vis[id[z]] = 1;
        return;
    }
    for(int j = i + 1 ; j < n ; j++){
        if(vis[j] == 0 && s + a[j] <= sum){ // nếu j chưa được đánh dấu
            id.push_back(j); // thử vị trí j  , a[j] là giá trị
            Try(j,s+a[j],id); // Gọi đệ quy
            id.pop_back();   // xoá j khỏi vector
        }
    }
    
}
void Solve(){
    sum = cnt = 0; // khơi tạo lại cho mỗi bộ test.
    for(int i = 0 ; i < n ; i++) sum += a[i];
    if(sum % k != 0 || *max_element(a.begin(),a.end()) > sum/k){
        cout << 0 << '\n';
        return;
    }
    vector < int > tmp; // move
    sum /= k;
    Try(-1,0,tmp);
    cout << ( cnt == k ) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}