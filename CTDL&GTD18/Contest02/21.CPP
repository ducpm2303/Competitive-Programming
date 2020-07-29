/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
int test = 1 , MULTI_TEST = 1;
string a;
void Input(){
    cin >> a;
}   
void Solve(){
    cout << a << ' ';
    while(next_permutation(a.begin(),a.end())){
        cout << a << ' ';
    }
    cout << '\n';
}
int main(){
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 