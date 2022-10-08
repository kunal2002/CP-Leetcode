class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        string res = "";
        string rev = "";
        for(int i = 0; i < n; i++)
        {
            int l = i,r = i;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                res = s[l] + res;
                if(l != r)
                rev += s[r];
                l--;
                r++;
            }
            if((res.size() + rev.size()) > ans.size())
            {
                ans = res + rev;
            }
            res = "";
            rev = "";
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                res = s[l] + res;
                if(l != r)
                rev += s[r];
                l--;
                r++;
            }
            if((res.size() + rev.size()) > ans.size())
            {
                ans = res + rev;
            }
            res = "";
            rev = "";
        }
        return ans;
        }
};
