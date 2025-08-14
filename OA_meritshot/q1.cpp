/*
1. Sales Report Analysis
Scenario:
A store records sales for each day of a month. At the end, management wants to know
which day had the highest sales, which had the lowest, and the average sales.
Problem:
Given an array of integers representing daily sales, write a program to:
Find the maximum sales value and its day number.
Find the minimum sales value and its day number.
Calculate the average sales for the month.
Constraints:
1<= number of days <= 31
Sales values are positive integers <= 10^6
Use only loops and basic array operations (no built-in max/min functions).
*/
// Q1: Sales Report Analysis
// Language: C++
#include <iostream>
using namespace std;
int main() {
    int day;
    cout << "Enter number of days: ";
    cin >> day;
    if (day < 1 || day > 31) {
        cout << "Invalid! Please enter between 1 and 31";
        return 0;
    }
    int sales[31];
    cout << "Enter sales for " << day << " days:\n";
    for (int i = 0; i < day; i++) {
        cin >> sales[i];
        if (sales[i] <= 0) { 
            cout << "Sales value must be positive!";
            return 0;
        }
    }
    int maxSales = sales[0], minSales = sales[0];
    int maxDay = 1, minDay = 1;
    long long sum = 0;
    for (int i = 0; i < day; i++) {
        sum += sales[i];
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxDay = i + 1; 
        }
        if (sales[i] < minSales) {
            minSales = sales[i];
            minDay = i + 1;
        }
    }
    double average = (double)sum / day;
    cout << "Highest Sales: " << maxSales << " on Day " << maxDay << "\n";
    cout << "Lowest Sales: " << minSales << " on Day " << minDay << "\n";
    cout << "Average Sales: " << average << "\n";
    return 0;
}

/*
Approach:
Store sales for each day in an array, then iterate once to track the highest 
and lowest sales along with their day numbers, while also summing all sales. 
The average is computed as total sum divided by number of days.
Time Complexity: O(n)
Space Complexity: O(1) extra space
*/
