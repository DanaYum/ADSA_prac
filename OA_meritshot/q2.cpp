/*
2. Student Ranking
Scenario:
A teacher wants to arrange student marks in descending order without using built-in
sort functions.
Problem:
Given an array of marks, sort them using selection sort and display the sorted list.
Constraints:
1 <= number of students <=1000
Marks are integers between 0 and 100

No built-in sort functions allowed.
*/
// Q2: Student Ranking
// Language: C++

// Q2: Student Ranking
// Language: C++

#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of students (max 1000): ";
    cin >> n;
    if (n < 1 || n > 1000) {
        cout << "Invalid number of students!";
        return 0;
    }
    int marks[1000];
    cout << "Enter marks for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Marks must be between 0 and 100!";
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (marks[j] > marks[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = marks[i];
        marks[i] = marks[maxIndex];
        marks[maxIndex] = temp;
    }
    cout << "Sorted Marks in Descending Order:\n";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
Approach:
Use selection sort to arrange marks in descending order by repeatedly finding 
the maximum element from the unsorted part and swapping it with the first unsorted 
element.
Time Complexity: O(n^2)
Space Complexity: O(1) extra space
*/
