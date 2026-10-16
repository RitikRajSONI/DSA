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
    void DFS(TreeNode* root, vector<int>& curpath, vector<vector<int>>& res,int cs , int ts){
        cs+=root->val;
        curpath.push_back(root->val);
        if(!root->left && !root->right){
            if(cs==ts) res.push_back(curpath);
        }else{
            if(root->left) DFS(root->left,curpath,res,cs,ts);
            if(root->right) DFS(root->right,curpath,res,cs,ts);
        }

        curpath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curpath;

        if (!root) return res;
        
        DFS(root,curpath,res,0,targetSum);
        return res;
    }
};