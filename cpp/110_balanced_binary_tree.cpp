//
// Created by bowen on 2020/8/22.
//

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
    bool isB;
    bool isBalanced(TreeNode* root) {
        isB = true;
        doIt(root);
        return isB;
    }

    int doIt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = doIt(root->left);
        int r = doIt(root->right);

        if (l - r <= 1 && r - l <= 1){

        }else{
            isB = false;
        }

        return max(l, r) + 1;
    }
};