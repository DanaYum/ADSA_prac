/*
4.Find K Smallest Elements (Heap)
Scenario:
You are given the prices of items in a shop. You need to find the k cheapest items.
Problem Statement
Given:
An array of item prices (size n).
A number k representing how many of the cheapest items to display.
Write a program to find the k smallest elements using a manually implemented
min heap.
Constraints
1 <= n <= 10^6
1 <= k <= n
No use of built-in heap or priority _ queue functions.
Heap must be manually implemented.
Time complexity should be O(n log n).
*/
// Q4: Find K Smallest Elements (Heap)
// Language: C++

#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
int extractMin(int arr[], int &n) {
    if (n <= 0)
        return -1;

    if (n == 1) {
        n--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);
    return root;
}

int main() {
    int n, k;
    cout << "Enter number of items: ";
    cin >> n;
    if (n < 1 || n > 100000) {
        cout << "Invalid number of items!";
        return 0;
    }
    int prices[n];
    cout << "Enter prices of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        if (prices[i] < 0) {
            cout << "Price can't be negative!";
            return 0;
        }
    }
    cout << "Enter k (number of cheapest items to find): ";
    cin >> k;
    if (k < 1 || k > n) {
        cout << "Invalid value of k!";
        return 0;
    }
    buildMinHeap(prices, n);
    cout << k << " cheapest items:\n";
    for (int i = 0; i < k; i++) {
        cout << extractMin(prices, n) << " ";
    }
    cout << "\n";
    return 0;
}

/*
Approach:
Implemented a manual min heap without using built-in priority_queue.
1. Built a min heap from the prices array in O(n) time.
2. Extracted the smallest element k times (each extraction takes O(log n)).
This gives an overall time complexity of O(n + k log n), which is within O(n log n).
Space Complexity: O(1) extra space.
*/
