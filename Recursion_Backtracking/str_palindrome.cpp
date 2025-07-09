#include<bits/stdc++.h>
using namespace std;
bool f(int i,string & str){
    if(i>=str.size()/2){
        return true;
    }
    if(str[i]!= str[str.size()-i-1]){
        return false;
    }
    f(i+1,str);
}
int main(){
    string str;
    cin>>str;
    if(f(0,str)){
        cout<<"Yes, it is a palindrome";
    } else {
        cout<<"No, it is not a palindrome";
    }
}