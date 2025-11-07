#include<bits/stdc++.h>
using namespace std;
string findAllSubstrings(string s) {
    string ans=" ";
    for(int i=0;i<s.size();i++){
        string temp=" ";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            ans+=temp+" ";
        }
    }
    return ans;
}
int main(){
    string s={'a','b','c'};
    cout<<findAllSubstrings(s);
    return 0;
}