//Memoization Solution

#include <bits/stdc++.h> 
int solve(int n,  vector<int> &heights, vector<int> &dp) {
    if(n == 0) 
    return 0;

    if(dp[n] != -1) return dp[n];

    int jumpone = solve(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int jumptwo = INT_MAX;
    
    if(n>1) {
        jumptwo = solve(n-2 , heights, dp) + abs(heights[n] - heights[n-2]);
    }

    return dp[n] = min(jumpone, jumptwo);
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n, -1);
    return solve(n-1, heights, dp);

    //TC = O(N)
    //SC = O(N)
    
}


//Tabulation Solution

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int ind = 1; ind < n; ind++) {
        int jumpone = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
        int jumptwo = INT_MAX;
        
        if(ind>1) {
            jumptwo = dp[ind-2] + abs(heights[ind] - heights[ind-2]);
        }

        dp[ind] = min(jumpone, jumptwo);
    }
    return dp[n-1];
}

//TC = O(N)
//SC = O(N)


//Space Optimized Solution

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{   
    int prev = 0;
    int prev2 = 0;

    for(int ind = 1; ind < n; ind++) {
        int jumpone = prev + abs(heights[ind] - heights[ind-1]);
        int jumptwo = INT_MAX;
        
        if(ind>1) {
            jumptwo = prev2 + abs(heights[ind] - heights[ind-2]);
        }

        int cur_i = min(jumpone, jumptwo);

        prev2 = prev;
        prev = cur_i;
    }
    return prev;

    //TC = O(N)
    //SC = O(1)
}