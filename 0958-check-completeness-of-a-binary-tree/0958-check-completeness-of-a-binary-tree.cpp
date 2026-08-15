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
class Solution {
public:
    int cn(TreeNode* root){
        if(root==NULL) return 0;
        return 1+cn(root->left)+cn(root->right);
    }
    bool isCBT(TreeNode* root, int idx, int tn){
        if(root==NULL) return true;
        if(idx>=tn){
            return false;
        }
        else{
            bool l = isCBT(root->left,idx*2+1,tn);
            bool r = isCBT(root->right,idx*2+2,tn);
            return l && r;
        }
    }
    bool isCompleteTree(TreeNode* root) {
        int idx=0;
        int tn=cn(root);
        return isCBT(root,idx,tn);
    }
};