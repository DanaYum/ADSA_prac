// memoization + printing LCS
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive + memoized function for LCS length
    int f(int i, int j, string &s, string &r, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0; // base case
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == r[j])
            return dp[i][j] = 1 + f(i - 1, j - 1, s, r, dp);
        else
            return dp[i][j] = max(f(i - 1, j, s, r, dp), f(i, j - 1, s, r, dp));
    }

    // Function to reconstruct the LCS string
    string buildLCS(string &s, string &r, vector<vector<int>> &dp) {
        int i = s.size() - 1;
        int j = r.size() - 1;
        int len = dp[i][j];
        string ans(len, '$'); 
        int index = len - 1;

        while (i >= 0 && j >= 0) {
            if (s[i] == r[j]) {
                ans[index] = s[i];
                index--;
                i--; j--;
            } else if (i > 0 && dp[i - 1][j] >= (j > 0 ? dp[i][j - 1] : 0)) {
                i--;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
    string s = "abcde";
    string r = "ace";
    int n = s.size(), m = r.size();

    // initialize dp with -1
    vector<vector<int>> dp(n, vector<int>(m, -1));

    Solution obj;
    int lcsLength = obj.f(n - 1, m - 1, s, r, dp);

    cout << "Length of LCS = " << lcsLength << endl;
    string ans = obj.buildLCS(s, r, dp);
    cout << "LCS = " << ans << endl;
    return 0;
}


// printing LCS using tabulation
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcde";
    string r = "ace";
    int n = s.size(), m = r.size();

    // Step 1: Build DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == r[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Reconstruct LCS
    int len = dp[n][m];         // length of LCS
    string ans(len, '$');       // placeholder string
    int i = n, j = m, index = len - 1;

    while (i > 0 && j > 0) {
        if (s[i - 1] == r[j - 1]) {
            ans[index] = s[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS: " << ans << endl;
    return 0;
}
