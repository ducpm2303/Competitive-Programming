//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n;
void GrayCode(int n) 
{ 
    vector < string > arr; 
    // n=1
    arr.push_back("0"); 
    arr.push_back("1"); 
    int i, j; 
    for (i = 2; i < (int)pow(2,n); i = i*2) 
    { 
    //coppy vector thanh 2 theo kieu phan chieu guong
        for (j = i-1 ; j >= 0 ; j--) 
            arr.push_back(arr[j]); 
  	//them 0 vao cac so phia trc
        for (j = 0 ; j < i ; j++) 
            arr[j] = "0" + arr[j]; 
  	//them 1 vao cac so phia sau
        for (j = i ; j < 2*i ; j++) 
            arr[j] = "1" + arr[j]; 
    }
    string tmp = "";
    for (i = 0 ; i < arr.size() ; i++ ) {
        
        cout << arr[i] << ' ';
    }
} 
void input(){
	cin >> n;
}
void solve(){
	GrayCode(n);
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
 