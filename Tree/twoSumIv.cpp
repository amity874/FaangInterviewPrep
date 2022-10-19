/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class bstIterator{
    stack<TreeNode*> mySt;
    bool isReverse;
    public:
    bstIterator(TreeNode* root,bool isReverse){
        this->isReverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return (not mySt.empty());
    }
    int next(){
        TreeNode *node=mySt.top();
        mySt.pop();
        if(isReverse){
            pushAll(node->left);
        }
        else{
            pushAll(node->right);
        }
        return node->val;
    }
    void pushAll(TreeNode *root){
        for(;root!=NULL;){
            mySt.push(root);
            if(isReverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bstIterator* it1=new bstIterator(root,false);
        bstIterator* it2=new bstIterator(root,true);
        int l=it1->next();
        int r=it2->next();
        while(l<r){
            if(l+r==k){
                return true;
            }
            else if(l+r>k){
                r=it2->next();
            }
            else{
                l=it1->next();
            }
        }
        return false;
    }
};