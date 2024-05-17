#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 knapsack problem
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create a 2D vector to store the maximum value that can be obtained
    // for each weight and each item
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the dp table using bottom-up dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            // If the current item's weight is less than or equal to the
            // current weight capacity 'w', then we have two choices:
            // 1. Include the current item
            // 2. Exclude the current item
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value that can be obtained will be stored in dp[n][W]
    return dp[n][W];
}

int main() {
    // Example data
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50; // Knapsack capacity
    int n = val.size(); // Number of items

    // Solve the knapsack problem and print the result
    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}

