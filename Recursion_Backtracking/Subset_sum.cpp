#include <bits/stdc++.h>
using namespace std;

void f(int ind, int sum, vector<int>& ds, int arr[], int n, vector<int>& subset) {
    if(ind == n) {
        subset.push_back(sum);
        return;
    }
    
    // Include current element
    ds.push_back(arr[ind]);
    f(ind + 1, sum + arr[ind], ds, arr, n, subset);

    // Exclude current element
    ds.pop_back();
    f(ind + 1, sum, ds, arr, n, subset);
}

int main() {
    int arr[3] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    vector<int> subset;

    f(0, 0, ds, arr, n, subset);

    // Print the subset sums
    for(int val : subset) {
        cout << val << " ";
    }

    return 0;
}
