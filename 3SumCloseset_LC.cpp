class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        n--;
        int ans = 1e5;
        for(int i = 0; i < n - 1; i++)
        {
            int start = i+1, end = n;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(abs(sum - target) < abs(ans - target))
                    ans = sum;
                if(target > sum)
                start++;
                else
                end--;
            }
        }
        return ans;
    }
};
