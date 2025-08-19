/*
13. Circular Queue for Parking
Scenario:
You manage a parking lot with a fixed number of spots.
Cars enter and leave in FIFO order, but since space is limited, the parking lot is
modeled as a circular queue.
Problem:
You need to support:
enqueue(carNumber) —+ A car enters.
dequeue() —+ The first car leaves.
display() —+ Show all cars currently parked in order.
Constraints:
Parking spots <= 1000

No built-in queue allowed - implement your own circular queue using an array.
*/
// Question 13: Circular Queue for Parking
// Language: C++
// No built-in queue used – manual circular queue implementation

#include <iostream>
using namespace std;
class CircularQueue {
private:
    int arr[1000]; // maximum parking spots
    int front, rear, count, capacity;
public:
    CircularQueue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    void enqueue(int carNumber) {
        if (count == capacity) {
            cout << "Parking lot full! Cannot park car " << carNumber << "\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = carNumber;
        count++;
    }
    void dequeue() {
        if (count == 0) {
            cout << "Parking lot empty! No car to remove.\n";
            return;
        }
        cout << "Car " << arr[front] << " left the parking lot.\n";
        front = (front + 1) % capacity;
        count--;
    }
    void display() {
        if (count == 0) {
            cout << "[Empty Parking Lot]\n";
            return;
        }
        cout << "Cars in parking lot: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << "\n";
    }
};
int main() {
    CircularQueue parking(1000);
    int choice, carNumber;
    cout << "Parking Lot Management (Circular Queue)\n";
    cout << "1. Park a car (enqueue)\n";
    cout << "2. Remove a car (dequeue)\n";
    cout << "3. Display parked cars\n";
    cout << "4. Exit\n";
    while (true) {
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter car number: ";
            cin >> carNumber;
            parking.enqueue(carNumber);
        }
        else if (choice == 2) {
            parking.dequeue();
        }
        else if (choice == 3) {
            parking.display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

/*
Approach:
We implemented a circular queue manually using a fixed-size array.
rear moves forward when a new car is added, wrapping around with modulo when it reaches the end.
front moves forward when a car leaves, also using modulo for wrap-around.
Count variable ensures O(1) checks for full/empty states.
This design avoids shifting elements and uses O(1) space for operations.
*/
