#include<bits/stdc++.h>
using namespace std;
//brute force 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};
//using hashing
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto it:mpp){
            if(it.second >nums.size()/2){
                return it.first;
            }
        }
        return 0;
    }
};