#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,maxlength=0;
        vector<int> hash(256,-1);
        int n=s.length();
        while(right<n){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            hash[s[right]]=right;
            int len=right-left +1;
            maxlength=max(len,maxlength);
            right++;
        }
        return maxlength;
    }
};