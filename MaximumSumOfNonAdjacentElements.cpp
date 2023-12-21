#include <bits/stdc++.h>

// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(n) [Recursive call stack]
int solve(vector<int> &nums, int n) {
    if (n == 0) {
        return nums[0];
    }
    if (n < 0) {
        return 0;
    }
    int incl = solve(nums, n - 2) + nums[n];
    int excl = solve(nums, n - 1);
    return std::max(incl, excl);
}

// Memoization Solution
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) [Recursive call stack + array space]
int memo(vector<int> &nums, int n, vector<int> &dp) {
    if (n == 0) {
        return nums[0];
    }
    if (n < 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int incl = solve(nums, n - 2) + nums[n];
    int excl = solve(nums, n - 1);
    dp[n] = std::max(incl, excl);
}

// Tabulation Solution
// Time Complexity: O(N)
// Space Complexity: O(N) [array space]
int tab(vector<int> nums, int n) {
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1] + 0;
        dp[i] = std::max(incl, excl);
    }
    return dp[n - 1];
}

// Best Optimized Solution
// Time Complexity: O(N)
// Space Complexity: O(1) [Constant Space]
int SO(vector<int> nums, int n) {
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++) {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = std::max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    // return solve(nums, n - 1);

    vector<int> dp(n + 1, -1);
    // return memo(nums, n - 1, dp);

    // return tab(nums, n);

    return SO(nums, n);
}

/*
    Recursive Solution 
    - Time Complexity: O(2^n)
    - Space Complexity: O(n) [Recursive call stack]

    Memoization Solution 
    - Time Complexity: O(n)
    - Space Complexity: O(n) + O(n) [Recursive call stack + array space]

    Tabulation Solution
    - Time Complexity: O(N)
    - Space Complexity: O(N) [array space]

    Best Optimized Solution 
    - Time Complexity: O(N)
    - Space Complexity: O(1) [Constant Space]
*/
