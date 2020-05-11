//Code By PMD
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
/*
    x^y > y^x --> ylog(x) > xlog(y) --> x/log(x) < y/log(y)
    sort + thamlam + chat nhi phan;
    voi moi xlogx[i] tim vi tri id dau tien ma ylogy[id] > xlogx[i] bang chat nhi phan
    res += (m-id);
*/
const int maxN = 1e5+5;
const double inf = 1.0*1e9 ;
int a[maxN],b[maxN],n,m;


void input(){
    cin >> n >> m;;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < m ; i++)
        cin >> b[i];
}
void solve(){
    int db0 = 0, db1 = 0 , da = 0;
    vector < double > xlogx , ylogy;
    for(int i = 0 ; i < n ; i++){
        if( a[i] == 1 ) da ++;
        double tmp = 1.0*a[i]/log10(a[i]);
        if ( a[i] > 1) xlogx.push_back(tmp);
    }
    for(int i = 0 ; i < m ; i++){
        if (b[i] == 0 ) db0++;
        else if(b[i] == 1) db1++;
        else{
            double tmp = 1.0*b[i]/log10(b[i]);
            ylogy.push_back(tmp);
        }
    }
    sort(xlogx.begin(),xlogx.end());
    sort(ylogy.begin(),ylogy.end());
    long long res = 0;
    for(int i = 0 ; i < xlogx.size(); i++){
        int id = upper_bound(ylogy.begin(),ylogy.end(),xlogx[i]) - ylogy.begin();
        res += 1LL*(ylogy.size() - id) + db0 + db1;
    }
    res += da*db0;
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1; 
    cin>>t; 
    while(t--){ 
        input();
        solve();
    }
    return 0;
}
//Code By PMD
 
