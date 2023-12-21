class Solution {

private:
    int ways(int n, vector<int> &dp) {
        if(n<=1) return 1;
        
        if(dp[n] != -1) return dp[n];

        return dp[n] = ways(n-1 ,dp) + ways(n-2, dp);
    }

public:
    int climbStairs(int n) {

        //Recursive Solution
        /*if(n==0 or n==1) {
            return 1;
        }
        return climbStairs(n-1)+climbStairs(n-2);*/


        //Memoization Solution ways function is written in private section
        /*
        vector<int> dp(n+1, -1);
        return ways(n, dp);
        */


        //Tabulation Solution
        /*
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        */


        //Optimized Solution
        int prev2 = 1;
        int prev = 1;
        if(n <= 2) return n;
        for(int i = 2; i <= n; i++) {
            int curr_i = prev + prev2;
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
        

        /*
            **Recursive Solution 
            -Time Complexity = O(n)
            -Space Complexity = O(n)[Recursive call stack]

            **Memoization Solution 
            -Time Complexity = O(n)
            -Space Complexity = O(n) + O(n) [Recursive call stack + array space]

            **Tabulation Solution
            -Time Complexity = O(N)
            -Space Complexity = O(N) [array space]

            **Best Optimized Solution 
            -Time Complexity = O(N)
            -Space Complexity = O(1) [Constant Space]
        */


    }
};