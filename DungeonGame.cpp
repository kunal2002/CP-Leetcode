/* 174. Dungeon Game  Link: https://leetcode.com/problems/dungeon-game/   */
/* The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned. 
Example :1 
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
*/
#include<bits/stdc++.h>
using namespace std;
 // dp:  given example
    //   [7,5,2]
    //   [6,11,5]
    //   [1,1,  ]
    int topdown(int i,int j,vector<vector<int>>&dung,vector<vector<int>>&dp,int m,int n){
        if(i==m||j==n) return 1e9;
        if(i==m-1&&j==n-1){
           return dp[i][j]=(dung[i][j]<=0)?-dung[i][j]+1:1;
        }
        if(dp[i][j]!=1e9) return dp[i][j];
        int godown=topdown(i+1,j,dung,dp,m,n);
        int goright=topdown(i,j+1,dung,dp,m,n);
        int reqhealth=min(godown,goright)-dung[i][j];
        dp[i][j]=(reqhealth<=0)?1:reqhealth;
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
         int m=dungeon.size();
         int n=dungeon[0].size();
         vector<vector<int>>dp(m,vector<int>(n,1e9));
         return topdown(0,0,dungeon,dp,m,n);
    }