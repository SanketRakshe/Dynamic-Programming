class Solution {
public:
    int fib(int n) {
        /*
        //Recursive Solution
        //base case
        if(n <= 1)
        return n;
        //Recursive Relation
        return fib(n-1) + fib(n-2);
        */


        /*
        //Memoization Solution
        vector<int> dp(n);
        if(n<=1)
        return n;

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
        */


        /*
        //Tabulation solution
        vector<int> dp(n+1);
        if(n<2) return n;
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        */

        //best space optimized solution
        int prev2 = 0;
        int prev = 1;

        if(n < 2) return n;
        for(int i = 2; i <= n; i++) {
            int curr_i = prev + prev2;
            prev2 = prev;
            prev = curr_i;
        }
        return prev;

        /*
            **Recursive Solution 
            -Time Complexity = O(2^n)
            -Space Complexity = O(n) [Recursive call stack]

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