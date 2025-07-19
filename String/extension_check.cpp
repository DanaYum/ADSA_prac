#include <iostream>
#include <string>

using namespace std;

// Function to check if a string is a valid java file
bool isJavaFile(const string& str) {
    int len = str.length();
    return len > 5 && str.substr(len - 5) == ".java";
}

int main() {
    int m=10, n=11;
    string str1="dhana.java";
    string str2="yumnam.cpp";

    

    // Case 1: Both strings are empty
    if (m == 0 && n == 0) {
        cout << -1 << endl;
    }
    else {
        bool isJava1 = (m > 0 && isJavaFile(str1));
        bool isJava2 = (n > 0 && isJavaFile(str2));

        if (isJava1 && isJava2) {
            cout << 2 << endl;
        }
        else if (isJava1 || isJava2) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}
