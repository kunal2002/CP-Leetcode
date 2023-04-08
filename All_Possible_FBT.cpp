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

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 0)
            return {};
        if(n == 1)
            return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 0; i < n; i++)
        {   // (root - 1) left to sort in right and leftTree
            int r = n - 1 - i;
            vector<TreeNode*> leftTree,rightTree;
            leftTree = allPossibleFBT(i);
            rightTree = allPossibleFBT(r);
            for(auto x: leftTree)
            {
                // cout << i << " ";
                for(auto y: rightTree)
                {
                    TreeNode* root = new TreeNode(0, x, y);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
