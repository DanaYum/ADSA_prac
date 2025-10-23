#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arrays) {
    sort(arrays.begin(), arrays.end());
    vector<vector<int>> merged;

    for (int i = 0; i < arrays.size(); i++) {
        if (merged.empty() || merged.back()[1] < arrays[i][0]) {
            merged.push_back(arrays[i]);
        } else {
            merged.back()[1] = max(merged.back()[1], arrays[i][1]);
        }
    }

    return merged;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> mergedIntervals = mergeOverlappingIntervals(intervals);

    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}