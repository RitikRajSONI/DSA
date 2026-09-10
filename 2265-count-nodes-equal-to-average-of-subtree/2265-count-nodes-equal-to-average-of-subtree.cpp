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
    int ans=0;
    pair<int,int> findMeanNodes(TreeNode* root){
        if(root==NULL) return {0,0};

        auto [lsum,lcnt] = findMeanNodes(root->left);
        auto [rsum,rcnt] = findMeanNodes(root->right);
        int totalSum = lsum + rsum + root->val;
        int totalCount = lcnt + rcnt + 1;

        if(totalSum / totalCount == root->val) 
            ans++;
        
        return {totalSum,totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        findMeanNodes(root);
        return ans;
    }
};