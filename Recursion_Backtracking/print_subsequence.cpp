#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int>& ds, int arr[], int n) {
    if (ind == n) {
        for (int i = 0; i < ds.size(); ++i) {
            cout << ds[i]<<" ";
        }
        if (ds.size() == 0) {
            cout << "{}"; // Print empty set if no elements are selected
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    f(ind + 1, ds, arr, n);
    ds.pop_back();
    f(ind + 1, ds, arr, n);
}

int main() {
    int arr[3] = {3, 1, 2};
    vector<int> ds;
    f(0, ds, arr, 3);
}