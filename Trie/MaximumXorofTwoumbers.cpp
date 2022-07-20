#include<bits/stdc++.h>
class Node {
public:
    Node* left; // 0
    Node* right; // 1
};
class Trie {
private:
Node* root;
public:
Trie(){
        root=new Node();
}
void insert(int n) {
    Node* curr = root;
    for(int i=31;i>=0;i--){
        int bit=(n>>i)&1;
        if(bit==0){
            if(curr->left==NULL){
                curr->left=new Node();
            }
              curr=curr->left;
        }
        else{
            if(curr->right==NULL){
                curr->right=new Node();
            }
               curr=curr->right;
        }
    }
}
int findMaxXorPair(int n) {
    Node * curr=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit=(n>>i)&1;
        if(bit==0){
            if(curr->right!=NULL){
                //we got a opposite bit we go right
                curr=curr->right;
                ans=ans xor (1<<i);
            }
            else{
                curr=curr->left;//need to seetle with zero
            }
        }
        else{
            if(curr->left!=NULL){
                curr=curr->left;
                ans=ans xor (1<<i);
            }
            else{
                curr=curr->right;
            }
        }
    }
    return ans;
}
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    int ans=INT_MIN;
    Trie *tr=new Trie();
    for(auto &it:arr1){
        tr->insert(it);
    }
    for(auto &it:arr2){
        ans=max(ans,tr->findMaxXorPair(it));
    }
    return ans;
}