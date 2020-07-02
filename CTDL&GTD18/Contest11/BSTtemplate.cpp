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
bool Search(Node* root,int val){
    if(root == NULL) 
        return false;
    if(root->value == val) 
        return true;
    else if(val < root->value)
        return Search(root->left,val);
    else 
        return Search(root->right,val);
}
int leftmostValue(Node* root){
    while(root->left != NULL) root = root->left;
    return root->value;
}
Node* Delete(Node* root, int val){
    if(root == NULL) return root; // node la'
    if(val < root->value) 
        root->left  = Delete(root->left,val);
    else if(val > root->value) 
        root->right = Delete(root->right,val);
    else{ // val == root->value
        // 1 child
        if(root->left == NULL){
            Node* newRoot = root->right;
            free(root);
            return newRoot;
        }
        if(root->right == NULL){
            Node* newRoot = root->left;
            free(root);
            return newRoot;
        }
        // 2 child
        root->value = leftmostValue(root->right);
        cout << root->value << '\n';
        root->right = Delete(root->right,root->value);
    }
    return root;
}
void preOrder(Node* root){
    if(root != NULL){
        cout << root->value << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->value << ' ';
        inOrder(root->right);
    }
}
void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << ' ';
    }
}
Node* root = NULL;
void Display(){
    cout << "\nPreorder:";
    preOrder(root);
    cout << "\nInorder:";
    inOrder(root);
    cout << "\npostorder:";
    postOrder(root);
}
void Input(){
    
}
void Solve(){
    root = Insert( root, 25 );
    root = Insert( root, 15 );
    root = Insert( root, 50 );
    root = Insert( root, 10 );
    root = Insert( root, 22 );
    root = Insert( root, 35 );
    root = Insert( root, 70 );
    root = Insert( root, 4 );
    root = Insert( root, 12 );
    root = Insert( root, 18 );
    root = Insert( root, 24 );
    root = Insert( root, 31 );
    root = Insert( root, 44 );
    root = Insert( root, 66 );
    root = Insert( root, 90 );
    Display();
    // cout << "\nThu them phan tu 15 vao BTS";
    // Insert(root, 15);
    // Display();
   
    // cout << "\n==Thu xoa phan tu 50 khoi BTS==";
    // Delete(root, 50);
    // Display();

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
