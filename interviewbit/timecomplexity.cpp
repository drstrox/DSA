https://www.interviewbit.com/problems/climbing-stairs/

//brute force (2^n)
int minCost(int i, vector<int>& A, int n) {
    if (i >= n) return 0; // gone past the last stair
    if (i == n - 1) return A[i]; // base case: at last stair

    // Try both paths and take the cheaper one
    int cost1 = A[i] + minCost(i + 1, A, n);
    int cost2 = A[i] + minCost(i + 2, A, n);

    return min(cost1, cost2);
}

int solve(vector<int>& A) {
    return minCost(1, A, A.size());  // start from stair 0
}


//optimal solution using DP (n)
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;
    if (n == 1) return A[0];

    vector<int> dp(n);
    dp[0] = A[0];
    dp[1] = A[0] + A[1];

    for (int i = 2; i < n; i++) {
        dp[i] = A[i] + min(dp[i - 1], dp[i - 2]);
    }

    return dp[n - 1];
}