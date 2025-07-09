#include<bits/stdc++.h>
using namespace std;
// void f(int n,int sum){
//     if(n<1){
//         cout<<sum<<" ";
//         return;
//     }
//     f(n-1,sum+n);
// }
// int main(){
//     int n;
//     cin>>n;
//     int sum=0;
//     f(n,sum);
//     return 0;
// }
int f(int n){
    if(n==0) return 0;
    return n + f(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
}