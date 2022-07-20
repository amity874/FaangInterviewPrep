#include<bits/stdc++.h>
using namespace std;
#define ll                 long long int
struct TrieNode{
    TrieNode *left;
    TrieNode *right;
};
struct Trie {
    TrieNode *root;
    Trie(){
        root=new TrieNode();
    }
     void insert(ll n) {
     TrieNode *curr = root;
     for(int i = 31; i >= 0; i--) {
         int bit = (n >> i) & 1;
         if(bit == 0) {
             if(curr->left==NULL) {
                 curr->left = new TrieNode();
             }
             curr = curr->left;
         } else {
             if(curr->right == NULL) {
                 curr->right = new TrieNode();
             }
             curr = curr->right;
         }
     }
 }
    ll get_max(int value) {
    ll curr_xor = 0;
    TrieNode *curr = root;
    for(int i = 31; i >= 0; i--) {
        int bit = (value >> i) & 1;
        if(bit == 0) {
            // we desire to have a 1 that means right child should be there
            if(curr->right != NULL) {
                curr = curr->right;
                curr_xor += (1 << i);
            } else {
                curr = curr->left;
            }
        } else {
            // we desire to have a 0 that means left child should be there
            if(curr->left != NULL) {
                curr = curr->left;
                curr_xor += (1 << i);
            } else {
                curr = curr->right;
            }
        }
    }
    return curr_xor;
}
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> ans(queries.size(), 0); 
    vector<vector<ll>> offlineQueries; 
    int n=queries.size();
    std::sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        ll ai=queries[i][1];
        ll xi=queries[i][0];
        offlineQueries.push_back({ai,xi,i});
    }
    std::sort(offlineQueries.begin(),offlineQueries.end());
    Trie *tr=new Trie();
    int idx=0;
    for(auto &it:offlineQueries){
        ll qidx=it[2];
        ll ai=it[0];
        ll xi=it[1];
        while(idx<arr.size() && arr[idx]<=ai){
            tr->insert(arr[idx]);
            idx++;
        }
        if(idx==0){
            ans[qidx]=-1;
        }
        else{
            ans[qidx]=tr->get_max(xi);
        }
    }
    return ans;
}