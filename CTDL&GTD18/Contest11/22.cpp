/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value = v;
        left = right = NULL;
    }
};
Node* Insert(Node* root,int val){
    if(root == NULL) return new Node(val);
    if(val < root->value) 
        root->left = Insert(root->left,val);
    else if(val > root->value) 
        root->right = Insert(root->right,val);
    return root;
}
void middleNode(Node* root, int &cnt){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cnt++;
    middleNode(root->left,cnt);
    middleNode(root->right,cnt); 
}
Node* root;
void Input(){
    int n; cin >> n;
    root = NULL;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        root = Insert(root,x);
    }   
}   
void Solve(){
    int cnt = 0;
    middleNode(root,cnt);
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
