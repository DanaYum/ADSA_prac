#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(vector<int>& nums,int goal){
        int left=0,right=0,sum=0,count=0;
        while(right<nums.size()){
            if(goal<0) return 0;
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count=count+(right-left+1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};