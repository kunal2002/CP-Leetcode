class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> str;
        int sz = target.size();
        int j = 0;
        for(int i = 1; i <= n; i++)
        {
            int ctr = 0;
            while(target[j] != i)
            {
                ctr++;
                str.push_back("Push");
                i++;
            }
            while(ctr--)
            {
                str.push_back("Pop");
            }
            str.push_back("Push");
            if(j+1 < sz)
                j++;
            else
                break;
        }
        return str;
    }
};
