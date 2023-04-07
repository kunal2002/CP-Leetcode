/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* MakeParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp,int start)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* Kunal;
    while(!q.empty())
    {
        auto it = q.front(); q.pop();
        if(it->val == start)
            Kunal = it;
        if(it->left)
        {
            q.push(it->left);
            mp[it->left] = it;
        }
        if(it->right)
        {
            q.push(it->right);
            mp[it->right] = it;
        }
    }
    return Kunal;
}
int Solution::solve(TreeNode* A, int B) {
     unordered_map <TreeNode*, TreeNode*> mp;
    TreeNode* Kn = MakeParent(A, mp, B);
    queue<TreeNode*> q;
    q.push(Kn);
    unordered_map<TreeNode*, bool> vis;
    vis[Kn] = true;
    int burn = 0;
    while(!q.empty())
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            auto it = q.front(); q.pop();
            if(it->left && !vis[it->left])
            {
                q.push(it->left);
                vis[it->left] = true;
            }
            if(it->right && !vis[it->right])
            {
                q.push(it->right);
                vis[it->right] = true;
            }
            if(mp[it] && !vis[mp[it]])
            {
                q.push(mp[it]);
                vis[mp[it]] = true;
            }
        }
        burn++;
    }
    return burn - 1;
}
