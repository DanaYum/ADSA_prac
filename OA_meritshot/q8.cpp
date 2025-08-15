/*
8. Longest Repeating Character Replacement
Scenario:
A text compression algorithm can replace at most k characters in a substring
make all characters identical.
We need to figure out the maximum possible length of such a substring.
Problem:
Given:
str —> a string of uppercase letters A—Z.
k —> max number of characters you can replace.

Find:
The length of the longest substring where replacing at most k characters will make all characters the same.
Constraints:
 Only uppercase letters allowed (A—Z). 
 O(n) or O(n log n) solution required- brute force is not allowed.
 */
// Q8: Longest Repeating Character Replacement
// Language: C++

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int k;
    cout << "Enter string (A-Z only): ";
    cin >> str;
    cout << "Enter k: ";
    cin >> k;
    int n = str.length();
    if (n == 0) {
        cout << 0;
        return 0;
    }
    int freq[26] = {0};
    int left = 0, maxFreq = 0, maxLen = 0;
    for (int right = 0; right < n; right++) {
        int idx = str[right] - 'A';
        freq[idx]++;
        if (freq[idx] > maxFreq) maxFreq = freq[idx];
        while ((right - left + 1) - maxFreq > k) {
            freq[str[left] - 'A']--;
            left++;
        }
        if (right - left + 1 > maxLen) {
            maxLen = right - left + 1;
        }
    }
    cout << "Longest length: " << maxLen;
    return 0;
}

/*
Approach:
1. Sliding window with frequency tracking.
2. maxFreq keeps track of the count of the most common char in the current window.
3. If window length - maxFreq > k, shrink from left.
4. O(n) time, O(1) space (since alphabet is fixed to 26 letters).
*/
