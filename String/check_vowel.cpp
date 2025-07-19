#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    string str;
    cin >> str;

    string result = "";
    char lastChar = '\0'; // Track last added 'C' or 'V'

    for (char ch : str) {
        char curr = isVowel(ch) ? 'V' : 'C';

        // Only add if it's different from the last added character
        if (curr != lastChar) {
            result += curr;
            lastChar = curr;
        }
    }
    // input=whereabouts
    // output=CVCVCVC
    cout << result << endl;
    return 0;
}
