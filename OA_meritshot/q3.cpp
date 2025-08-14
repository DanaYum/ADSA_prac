/*
3. Rotate an Array
Scenario:
In a game leaderboard, the top k players are moved to the end after each round.
Problem:
Write a program to rotate the array of player IDs by k positions without using extra
space.
Constraints:
1 <= n <= 10^6
0 <= k < n
O(1) extra space, O(n) time complexity.
*/
// Q3: Rotate an Array
// Language: C++

#include <iostream>
using namespace std;
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int n, k;
    cout << "Enter number of players: ";
    cin >> n;
    if (n < 1 || n > 1000000) {
        cout << "Invalid number of players!";
        return 0;
    }
    int arr[n];
    cout << "Enter player ID:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> k;
    if (k < 0 || k >= n) {
        cout << "Invalid value of k!";
        return 0;
    }
    reverseArray(arr, 0, k - 1);     // Reverse first k elements
    reverseArray(arr, k, n - 1);     // Reverse remaining n-k elements
    reverseArray(arr, 0, n - 1);     // Reverse the whole array
    cout << "Array after rotation of player IDs by K position:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
Approach:
We rotate the array by k positions using the reversal algorithm:
1. Reverse the first k elements.
2. Reverse the remaining n-k elements.
3. Reverse the entire array.
This achieves rotation in O(n) time and O(1) extra space.
Time Complexity: O(n)
Space Complexity: O(1)
*/
