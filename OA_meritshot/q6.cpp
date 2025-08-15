/*
6. Word Frequency Counter
Scenario:
In a chat application, the system needs to analyze messages and determine how many
times each word appears. This is useful for spam detection, trending word analysis,
or keyword tracking.
The counting must be case-insensitive (e.g., "Hello" and "hello" should be treated as
the same word).
Problem:
Given a sentence, count how many times each unique word appears, ignoring case.
You cannot use built-in map or dictionary data structures - you must implement the
counting manually using arrays or a linked list.
Constraints:
Sentence length <= 1000 characters

Words are separated by spaces.
Case-insensitive comparison. 
No built-in map / unordered_map / dictionary allowed.
*/
// Q6: Word Frequency Counter
// Language: C++

#include <iostream>
#include <string>
using namespace std;
void toLowerCase(string &s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A');
        }
    }
}
int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    if (sentence.length() > 1000) {
        cout << "Invalid!";
        return 0;
    } 
    toLowerCase(sentence);
    string words[500];
    int freq[500] = {0}; 
    int wordCount = 0;
    string currentWord = "";
    for (int i = 0; i <= sentence.length(); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\0') {
            currentWord += sentence[i];
        } else {
            if (currentWord != "") {
                bool found = false;
                for (int j = 0; j < wordCount; j++) {
                    if (words[j] == currentWord) {
                        freq[j]++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    words[wordCount] = currentWord;
                    freq[wordCount] = 1;
                    wordCount++;
                }
                currentWord = "";
            }
        }
    }
    cout << "\nWord Frequency:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << ": " << freq[i] << "\n";
    }

    return 0;
}

/*
Approach:
1. Convert the sentence to lowercase manually.
2. Split words by spaces without using built-in functions like map/dictionary.
3. Store each unique word in an array and track its frequency in a parallel array.
4. Print word-frequency pairs.
Time Complexity: O(n * m) where n = number of words, m = unique words.
Space Complexity: O(m) for storing unique words.
*/
