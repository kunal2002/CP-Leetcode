#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n = arr.size();
  vector<int> pre(n, 0);
  if(n == 1 && arr[0])
    return 1;
  pre[0] = arr[0];
  map<int,int> mp;
  mp[arr[0]] = 1;
  int longest = 0;
  for(int i = 1; i < n; i++)
  {
    pre[i] = pre[i - 1] + arr[i];
    if(pre[i] == 0)
      longest = max(longest, i + 1);
    if(mp[pre[i]])
      longest = max(longest, i - mp[pre[i]] + 1);
    else
      mp[pre[i]] = i + 1;
  }
  
  return longest;
}
