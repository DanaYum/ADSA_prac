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