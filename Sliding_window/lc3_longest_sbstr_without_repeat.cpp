//3. Longest Substring Without Repeating Characters
//brute force
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLength = 0;
//         int n = s.length();
        
//         for (int i = 0; i < n; i++) {
//             vector<int> hash(256, 0); // Reset hash for every new start index
//             for (int j = i; j < n; j++) {
//                 if (hash[s[j]] == 1) break;
//                 hash[s[j]] = 1;
//                 int len = j - i + 1;
//                 maxLength = max(maxLength, len);
//             }
//         }
        
//         return maxLength;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // Store last index of characters
        int left = 0, maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }
            hash[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

