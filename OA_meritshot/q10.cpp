/*
10. Train Coach Arrangement
Scenario:
You're designing a train management system.
Each coach in a train is connected to both the previous and the next coach.
The data structure should be a doubly linked list.
You need to allow:
Add coach at the front
Add coach at the end
Remove a coach from the middle (given the coach number)
Problem:
Create a doubly linked list with:
Add coach at front.
Add coach at end.
Remove a coach from middle.
Constraints:
Number of coaches <= 10^5
*/
// Q10: Train Coach Arrangement using Doubly Linked List
// Language: C++

#include <iostream>
using namespace std;
struct Coach {
    int number;
    Coach* prev;
    Coach* next;

    Coach(int num) {
        number = num;
        prev = nullptr;
        next = nullptr;
    }
};
class Train {
private:
    Coach* head;
    Coach* tail;

public:
    Train() {
        head = nullptr;
        tail = nullptr;
    }
    void addFront(int num) {
        Coach* newCoach = new Coach(num);
        if (head == nullptr) {
            head = tail = newCoach;
        } else {
            newCoach->next = head;
            head->prev = newCoach;
            head = newCoach;
        }
        cout << "Coach " << num << " added at front.\n";
    }
    void addEnd(int num) {
        Coach* newCoach = new Coach(num);
        if (tail == nullptr) {
            head = tail = newCoach;
        } else {
            tail->next = newCoach;
            newCoach->prev = tail;
            tail = newCoach;
        }
        cout << "Coach " << num << " added at end.\n";
    }
    void removeCoach(int num) {
        if (head == nullptr) {
            cout << "Train is empty.\n";
            return;
        }

        Coach* temp = head;
        while (temp != nullptr && temp->number != num) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Coach " << num << " not found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } 
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } 
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Coach " << num << " removed.\n";
    }
    void displayTrain() {
        if (head == nullptr) {
            cout << "Train is empty.\n";
            return;
        }
        cout << "Train coaches (front to end): ";
        Coach* temp = head;
        while (temp != nullptr) {
            cout << temp->number << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Train train;
    int choice, num;

    do {
        cout << "\n--- Train Coach Arrangement ---\n";
        cout << "1. Add Coach at Front\n";
        cout << "2. Add Coach at End\n";
        cout << "3. Remove Coach\n";
        cout << "4. Display Train\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> num;
                train.addFront(num);
                break;
            case 2:
                cout << "Enter coach number: ";
                cin >> num;
                train.addEnd(num);
                break;
            case 3:
                cout << "Enter coach number to remove: ";
                cin >> num;
                train.removeCoach(num);
                break;
            case 4:
                train.displayTrain();
                break;
            case 5:
                cout << "Exiting Train Management.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

/*
Features:
- Uses doubly linked list for bidirectional connection.
- Add coach at front or end.
- Remove any coach by number.
- Display current arrangement.
- Handles empty train and not-found cases.
*/
