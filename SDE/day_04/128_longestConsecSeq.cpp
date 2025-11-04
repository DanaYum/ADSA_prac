#include<bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int>& arr,int k){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==k){
            return true;
        }
    }
    return false;
}
int longestConsecutive(vector<int>& arr) {
    int longest=0;
    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        int count=1;
        while(linearSearch(arr,x+1)){
            count++;
            x++;
        }
        longest=max(longest,count);
    }
    return longest;
}
int main(){
    vector<int> arr={100,4,200,1,3,2};
    cout<<longestConsecutive(arr);
    return 0;
}
// beter approach 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int longest=0;
        int lastSmaller=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastSmaller){
                cnt+=1;
                lastSmaller=nums[i];
            }
            else if(nums[i] != lastSmaller){
                cnt=1;
                lastSmaller=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};