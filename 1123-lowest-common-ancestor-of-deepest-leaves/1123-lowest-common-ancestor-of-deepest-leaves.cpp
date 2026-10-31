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
    // Helper function that returns both the LCA and the max depth of the subtree
    pair<TreeNode*, int> helper(TreeNode* root) {
        if (!root) return {nullptr, 0};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        int left_depth = left.second;
        int right_depth = right.second;
        
        // If depths match, this node is a candidate LCA for the deepest leaves
        if (left_depth == right_depth) {
            return {root, left_depth + 1};
        }
        
        // Otherwise, pass up the LCA found in the deeper subtree
        if (left_depth > right_depth) {
            return {left.first, left_depth + 1};
        } else {
            return {right.first, right_depth + 1};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};
