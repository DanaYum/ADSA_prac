#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(n+m);
        int left=0,right=0;
        int ind=0;
        while(left<m && right<n){
            if(nums1[left] <= nums2[right]){
                nums3[ind]=nums1[left];
                ind++,left++;
            }
            else{
                nums3[ind]=nums2[right];
                ind++,right++;
            }
        }
        while(left<m){
            nums3[ind++]=nums1[left++];
        }
        while(right<n){
            nums3[ind++]=nums2[right++];
        }
        for(int i=0;i<n+m;i++){
            nums1[i]=nums3[i];
        }
    }
};