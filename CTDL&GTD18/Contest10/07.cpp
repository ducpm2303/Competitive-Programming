//Code By PMD
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define whatis(a) cout << #a " is " << (a) << endl;
using namespace std;
 
typedef long long i64;
const int N = 100005;
const i64 mod = 1e9+7;
const i64 inf = 1e18+7;
vector< vector< int > > a;
void solve() {
	int n , m;
    cin>> n >>m;
    a = vector<vector<int> > (n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>> x >>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(a[i].empty()) continue;
        for(int j=0;j<a[i].size();j++){
            int x = a[i][j];
            if(a[i].size() != a[x].size()){
                cout << "NO";
                return;
            }
        }
    }
	cout<< "YES";
}
main(){
	IOS;
	int t=1;
	cin>>t;
	while(t--){
		solve();
		cout << endl;
	}
}
//Code By PMD