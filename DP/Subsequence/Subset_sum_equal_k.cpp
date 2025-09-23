//subset sum equal to k

//Memoization technique
#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;            // base: sum found
    if (ind == 0) return (arr[0] == target); // base: only one element left

    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f(ind - 1, target, arr, dp); // don't include current element
    bool take = false;
    if (arr[ind] <= target) {
        take = f(ind - 1, target - arr[ind], arr, dp); // include current element
    }

    return dp[ind][target] = (notTake || take);
}

bool subSetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

int main() {
    int n = 4, k = 4;
    vector<int> arr = {2, 3, 1, 1};
    
    if (subSetSumToK(n, k, arr)) 
        cout << "Subset with sum " << k << " exists!" << endl;
    else 
        cout << "Subset with sum " << k << " does not exist!" << endl;

    return 0;
}
