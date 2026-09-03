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
    void fsum(TreeNode* root, bool isLeft, int& sum) {
        if (root == NULL) return;
        
        // If it is a leaf node and it is a left child
        if (root->left == NULL && root->right == NULL && isLeft) {
            sum += root->val;
        }
        
        // Traverse left with isLeft = true
        fsum(root->left, true, sum);
        
        // Traverse right with isLeft = false
        fsum(root->right, false, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        fsum(root, false, sum); // Root is not a left child of anything
        return sum;
    }
};