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
void findChild(Node* root){
    if(root == NULL) return;
    if(root->right == NULL && root->left == NULL)
        cout << root->value << ' ';
    else{
        findChild(root->left);
        findChild(root->right);
    }
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
   findChild(root);
   cout << '\n';
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
