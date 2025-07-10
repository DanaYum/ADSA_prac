#include<bits/stdc++.h>
using namespace std;
void f(int ind,int sum,int arr[],vector<int>& ds,int n,int k){
    if(ind == n){
        if(sum==k){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }

        return;
    }
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    f(ind+1,sum,arr,ds,n,k);
    ds.pop_back();
    sum-=arr[ind];
    f(ind+1,sum,arr,ds,n,k);

}
int main(){
    int arr[3]={1,2,1};
    vector<int> ds;
    int k=2;
    int sum=0;
    cout<<"The subsequences whose sum is "<<k<<" are: "<<endl;
    f(0,sum,arr,ds,3,k);
}