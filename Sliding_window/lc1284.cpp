//first solve lc930
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(vector<int>& nums,int k){
        int l=0,r=0,count=0,sum=0;
        if(k<0) return 0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> arr(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        return f(nums,k) - f(nums,k-1);
    }
};