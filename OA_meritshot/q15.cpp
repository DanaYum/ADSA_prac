/*
15. Priority-Based Job Scheduling (Heap)
Scenario:
You have a set of jobs, each with a priority value.
Jobs must be executed from highest priority to lowest priority.
Problem:
You need to implement a Max Heap manually (no built-in priority queue) to manage
job scheduling.
Constraints:
Number of jobs <= 10^5
Job priority values are positive integers.
No built-in priority queue allowed -implement Max Heap using arrays.
*/
// Question 15: Priority-Based Job Scheduling (Heap)
// Language: C++
// No built-in priority queue used – manual max heap implementation with arrays

#include <iostream>
using namespace std;
class MaxHeap {
private:
    int heap[105];
    int size;
    void heapifyUp(int index) {
        while (index > 1 && heap[index] > heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && heap[left] > heap[largest])
            largest = left;
        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insertJob(int priority) {
        size++;
        heap[size] = priority;
        heapifyUp(size);
    }

    int extractMax() {
        if (size == 0) {
            cout << "[No jobs in heap]\n";
            return -1;
        }
        int maxVal = heap[1];
        heap[1] = heap[size];
        size--;
        heapifyDown(1);
        return maxVal;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    MaxHeap jobs;
    int n, priority;

    cout << "Enter number of jobs (<= 10): ";
    cin >> n;

    cout << "Enter priority values of jobs:\n";
    for (int i = 0; i < n; i++) {
        cin >> priority;
        jobs.insertJob(priority);
    }

    cout << "\nExecuting jobs from highest to lowest priority:\n";
    while (!jobs.isEmpty()) {
        cout << "Job with priority " << jobs.extractMax() << " executed.\n";
    }

    return 0;
}

/*
Approach:
We implemented a manual Max Heap using an array (1-indexed for simpler child/parent calculation).
- Insertion uses heapifyUp to maintain max heap property.
- ExtractMax swaps root with last element, reduces heap size, then calls heapifyDown.
- This ensures the highest priority job is always executed first.
Time Complexity:
- Insertion: O(log n)
- Extraction: O(log n)
*/
