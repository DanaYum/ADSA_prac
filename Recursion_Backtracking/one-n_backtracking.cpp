#include<bits/stdc++.h>
using namespace std;   
void freverse(int i,int n){
    if(i>n) return;
    freverse(i+1,n);
    cout<<i<<" ";
}
void f(int n){
    if(n<1) return;
    f(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cin>>n;
    freverse(1,n);
    cout << endl; // To separate the two outputs
    f(n);
}