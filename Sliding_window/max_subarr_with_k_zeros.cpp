// lc 1004 solved using longest subarray with k zeros
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0,maxlength=0,zero_cnt=0;
        while(right<n){
            if(nums[right]==0){
                zero_cnt++;
            }
            while(zero_cnt>k){
                if(nums[left]==0){
                    zero_cnt--;
                }
                left++;
            }
            int len=right-left+1;
            maxlength=max(len,maxlength);
            right++;
        }
        return maxlength;
    }
};