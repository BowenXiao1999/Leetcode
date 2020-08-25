//
// Created by bowen on 2020/8/25.
//

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ret;
        if (root == NULL) return ret;
        vector<TreeNode*> stk{root};
        bool is = false;
        while (stk.size() != 0) {
            vector<int> cur;
            vector<TreeNode*> next;
            for (auto i : stk) {
                cur.push_back(i->val);
                if (i->left) next.push_back(i->left);
                if (i->right) next.push_back(i->right);

            }

            stk = next;
            if (is) reverse(cur.begin(), cur.end());
            ret.push_back(cur);
            is = !is;
        }

        return ret;
    }
};