//
// Created by bowen on 2020/9/13.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        }

        if (root == p || root == q) {return root;}

        auto i = lowestCommonAncestor(root->left, p, q);
        auto j = lowestCommonAncestor(root->right, p, q);

        if (i != NULL && j != NULL) return root;

        if (i == NULL) return j;
        else return i;
    }
};