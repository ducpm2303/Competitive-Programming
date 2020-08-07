/*----MDP_ITPTIT_D18TEAM4----*/
/*---------Library----------*/
#include<bits/stdc++.h>
/*------------Define------------*/
#define Faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi32 vector<int>
#define vi64 vector<i64>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
/*-----------------------------*/
using namespace std;
typedef long long i64;
typedef long double lb ;
const int N = 1e5+5;
const i64 mod = 1e9+7;
const i64 inf = 1e18+7;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
/*----------Functinons----------*/
struct data{
    int a[6] , stp;
};
int kt[6];
data tmp;
queue < data > q;
void swap( int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp; 
}
 
bool check(){
	data temp = q.front();
	for( int i = 0 ; i < 6; i++)
		if( temp.a[i] != kt[i])
				return true;
	return false;
}
void xoay( data cn){
	data cn1, cn2;
	cn1 = cn2 = cn;
	cn1.stp = cn2.stp = cn.stp +1;
	swap( cn1.a, cn1.a+1);
	swap( cn1.a+3, cn1.a+4);
	swap( cn1.a, cn1.a+4);
	q.push(cn1);
	swap( cn2.a+2, cn2.a+1);
	swap( cn2.a+4, cn2.a+5);
	swap( cn2.a+1, cn2.a+5);
	q.push(cn2);
}
void Input(){
	while(!q.empty()) q.pop();
	tmp.stp = 0;
	for( int i = 0 ; i < 6; i++) cin >> tmp.a[i];
	for( int i = 0 ; i < 6; i++) cin >> kt[i];
}	
void Solve(){
    q.push(tmp);
    while( check()){
		xoay(q.front());
		q.pop();
	}
    cout << q.front().stp << endl;
}
 
 
/*-----------Main------------*/
main(){
	Faster();
	int test=1;
	cin>>test;
	while(test--){
		Input();
		Solve();
		//cout<<endl;
	}
}
/*-----------Just_MDP-----------*/