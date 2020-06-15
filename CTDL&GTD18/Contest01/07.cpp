//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
vector < int > X(100),T(100);
vector < vector <int> > res;
int n;
void input(){
    cin >> n; res.clear();
}
bool cmp1(int x , int y){
    return x > y;
}
bool cmp(vector < int > x , vector < int > y){
    while(x.size() < y.size()) x.push_back(0);
    while(x.size() > y.size()) y.push_back(0);
    for(int i = 0 ; i < x.size() ; i++){
        if( x[i] == y[i]) continue;
        return(x[i] > y[i]);
    }
}
void Try(int i){
    int j;
    for(j = X[i - 1]; j <= (n - T[i - 1]); j++)  // X[i-1] <= X[i] <= n - T[i-1]
    {
        X[i] = j;
        T[i] = T[i - 1] + j;
        if(T[i] == n)   // nếu T[i] = n
        {
            int temp;
            vector < int > tmp;
            for(temp = 1;  temp <= i; temp++)   // in ra từ X[1] tới X[i]
            {   
                tmp.push_back(X[temp]);
            }
            res.push_back(tmp);
        }
        else
            Try(i + 1);
    }
}
void solve(){
    X[0] = 1 , T[0] = 0;
    Try(1);
    for(int i = 0 ; i < res.size() ; i++)
        sort(res[i].begin(),res[i].end(),cmp1);
    
    sort(res.begin(),res.end(),cmp);
    for(int i = 0 ; i < res.size() ; i++ ){
        cout << '(';
        for(int j = 0 ; j < res[i].size() ; j++){
            cout << res[i][j];
            if(j != res[i].size() - 1) cout << ' ';
        }
        cout << ") ";
    }
    cout << '\n';
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();
    int t=1; cin>>t;
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
 