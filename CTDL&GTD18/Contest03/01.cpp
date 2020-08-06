/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int test = 1 , MULTI_TEST = 1; 
int a[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int n;
void Input(){
    cin >> n;
}   
void Solve(){
    int res = 0;
    for(int i = 9 ; i >= 0 ; i--){
        while(n >= a[i]) n-=a[i],res++;
    }
    cout << res << '\n';
}
int main(){
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 