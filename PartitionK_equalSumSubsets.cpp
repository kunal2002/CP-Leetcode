class Solution {
public:
    bool rec(vector<int>& nums,vector<bool>& vis, int i, int target, int k, int s)
    {
        if(k == 1)
            return true;
        if(i >= nums.size())
        return false;
        if(target == 0)
            return rec(nums, vis, 0, s, k - 1, s);
        for(int l = i; l < nums.size(); l++)
        {
            if(vis[l] || (target < nums[l]))
                continue;
            vis[l] = true;
            if(rec(nums, vis, l + 1, target - nums[l], k , s))
                return true; 
            vis[l] = false;
        }  
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        if(sum % k != 0)
            return false;
        int target = sum / k;
        vector<bool> vis(nums.size(), false);
        bool res = rec(nums, vis, 0, target, k, target);
        return res;
    }
};
