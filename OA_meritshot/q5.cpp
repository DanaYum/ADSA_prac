/*
5. Username Validator
Scenario
A website has strict rules for creating usernames to ensure consistency and avoid
invalid entries. The rules are:
The username must start with a letter (A-Z or a-z).
It must have at least 5 characters.
It can contain only letters and digits (no spaces, symbols, or special characters).
You need to write a program to validate whether a given username follows these rules.
Problem Statement
Given a string representing a username, check if it meets the given rules.
If valid —> print "Valid Username".
If invalid —> print "Invalid Username".
Constraints
5 length 20
No use of built-in regex functions.
Only loops and basic character checks are allowed.
*/
// Q5: Username Validator
// Language: C++

#include <iostream>
#include <string>
using namespace std;

int main() {
    string username;
    cout << "Enter username: ";
    cin >> username;
    int length = username.length();
    if (length < 5 || length > 20) {
        cout << "Invalid Username. Length must be between 5 and 20 characters.\n";
        return 0;
    }
    if (!((username[0] >= 'A' && username[0] <= 'Z') || 
          (username[0] >= 'a' && username[0] <= 'z'))) {
        cout << "Invalid Username. First character must be a letter.\n";
        return 0;
    }
    for (int i = 0; i < length; i++) {
        char ch = username[i];
        if (!((ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z') ||
              (ch >= '0' && ch <= '9'))) {
            cout << "Invalid Username. Only letters and digits are allowed.\n";
            return 0;
        }
    }
    cout << "Valid Username\n";
    return 0;
}

/*
Approach:
1. Check if username length is between 5 and 20.
2. Verify first character is a letter (A-Z or a-z).
3. Loop through all characters and ensure each is a letter or digit.
No built-in regex or special functions are used.
Time Complexity: O(n)
Space Complexity: O(1) extra space
*/


