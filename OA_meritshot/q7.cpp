/*
7. Minimum Window Substring Finder
Scenario:
A search engine's query optimizer must highlight the smallest section of text
containing all the characters from the search query.
This must be done efficiently because the text can be up to characters long.
Problem:
Given:
A string T (the text).
A string S (set of characters to find).
Find the smallest substring of T containing all characters in S, case-insensitive.
If no such substring exists, output "No valid window found".
Constraints:
1 <= |S| <= 100
1 <= |T| <= 1000
No built-in substring search functions (like find() or regex). Implement your own
sliding window logic.
Optimize to O(n) time complexity.
*/
// Q7: Minimum Window Substring Finder
// Language: C++

#include <iostream>
#include <string>
using namespace std;

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

int main() {
    string T, S;
    cout << "Enter text (T): ";
    getline(cin, T);
    cout << "Enter search characters (S): ";
    getline(cin, S);

    if (T.length() == 0 || S.length() == 0) {
        cout << "No valid window found";
        return 0;
    }
    int targetFreq[256] = {0};
    for (char c : S) {
        targetFreq[(unsigned char)toLowerChar(c)]++;
    }
    int required = 0;
    for (int i = 0; i < 256; i++) {
        if (targetFreq[i] > 0) required++;
    }
    int left = 0, right = 0;
    int formed = 0;
    int windowFreq[256] = {0};

    int minLen = T.length() + 1;
    int minStart = 0;

    while (right < (int)T.length()) {
        char c = toLowerChar(T[right]);
        windowFreq[(unsigned char)c]++;

        if (targetFreq[(unsigned char)c] > 0 &&
            windowFreq[(unsigned char)c] == targetFreq[(unsigned char)c]) {
            formed++;
        }
        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char leftChar = toLowerChar(T[left]);
            windowFreq[(unsigned char)leftChar]--;

            if (targetFreq[(unsigned char)leftChar] > 0 &&
                windowFreq[(unsigned char)leftChar] < targetFreq[(unsigned char)leftChar]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    if (minLen > T.length()) {
        cout << "No valid window found";
    } else {
        cout << "Smallest window: ";
        for (int i = minStart; i < minStart + minLen; i++) {
            cout << T[i];
        }
    }
    return 0;
}

/*
Approach:
1. Count frequency of each character in S (case-insensitive).
2. Use two pointers (sliding window) to expand right and shrink left while maintaining character counts.
3. Track the smallest valid window.
4. Output manually without using built-in substring functions.
Time Complexity: O(n) where n = length of T.
Space Complexity: O(1) because we only use fixed-size arrays for frequencies.
*/
