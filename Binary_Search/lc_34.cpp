#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bs1(vector<int>& nums,int target,int first){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            if(target<nums[mid]) high=mid-1;
            if(target>nums[mid]) low=mid+1;
        }
        return first;
    }
    int bs2(vector<int>& nums,int target,int second){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                second=mid;
                low=mid+1;
            }
            if(target<nums[mid]) high=mid-1;
            if(target>nums[mid]) low=mid+1;
        }
        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first=bs1(nums,target,-1);
        int second=bs2(nums,target,-1);
        return {first,second};
        
    }
};