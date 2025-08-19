/*
12. Undo Feature in Text Editor
Scenario:
You're building a text editor.
Every time a user types a word, it's stored in a stack.
When the user presses Undo, the last typed word is removed from the text.
Problem:
Implement a stack where:
push = type a word.
pop = undo last word.
Constraints:
1 <= number of operations <= 10^5
Word length <= 50 characters
No built-in stack allowed - use array
*/
// Question 12: Undo Feature in Text Editor
// Language: C++
// No built-in stack used – manual array implementation

#include <iostream>
#include <string>
using namespace std;
class Stack {
private:
    string arr[100000]; 
    int topIndex;
public:
    Stack() {
        topIndex = -1;
    }
    void push(string word) {
        if (topIndex >= 99999) {
            cout << "Stack Overflow - cannot type more words\n";
            return;
        }
        arr[++topIndex] = word;
    }
    void pop() {
        if (topIndex == -1) {
            cout << "Nothing to undo\n";
            return;
        }
        topIndex--;
    }
    void display() {
        if (topIndex == -1) {
            cout << "[Empty Document]\n";
            return;
        }
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    Stack editor;
    int choice;
    string word;

    cout << "Text Editor - Undo Feature\n";
    cout << "1. Type word\n2. Undo last word\n3. Exit\n";

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter word: ";
            cin >> word;
            editor.push(word);
        }
        else if (choice == 2) {
            editor.pop();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
        cout << "Current Text: ";
        editor.display();
    }
    return 0;
}

/*
Approach:
We manually implemented a stack using an array of size 10^5.
Push operation inserts a word at the next index, Pop operation removes the last word.
Display function prints all current words in the document.
This meets O(1) space for operations and adheres to constraints.
*/
