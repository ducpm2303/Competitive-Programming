#include<bits/stdc++.h>
using namespace std;

int test = 1 , MULTI_TEST = 0;
int n,s,k,res = 0; 
void Try(int i , int k , int sum){
    if ( sum > s || k < 0) return;
    if( k == 0 && sum == s){
        res++;
        return;
    }
    for(int j = i + 1 ; j <= n ; j++)
        Try(j,k-1,sum+j);
}
void Input(){

}   
void Solve(){
    while(1){
        cin >> n >> k >> s;
        res = 0;
        if( n == 0 && s == 0 && k == 0){
            return;
        }
        Try(0,k,0);
        cout << res << '\n';
    }
}
int main(){
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}