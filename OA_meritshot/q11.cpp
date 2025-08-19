/*
11. Reverse a Linked List
Scenario:
You have a music playlist stored as a singly linked list,Each song points to the next
one in order.
You want to reverse the playlist in-place so the last song becomes the first, and so
on without using extra space.
Problem:
Reverse a singly linked list in-place.
Constraints:
1 <= nodes <= 10^5
O(1) extra space allowed.
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node(string s) {
        song = s;
        next = nullptr;
    }
};
class Playlist {
private:
    Node* head;
public:
    Playlist() {
        head = nullptr;
    }
    void addSong(string songName) {
        Node* newNode = new Node(songName);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->song;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr) {
            nextNode = curr->next; 
            curr->next = prev;     
            prev = curr;           
            curr = nextNode;       
        }
        head = prev; 
    }
};
int main() {
    Playlist playlist;
    playlist.addSong("Song1");
    playlist.addSong("Song2");
    playlist.addSong("Song3");
    playlist.addSong("Song4");

    cout << "Original Playlist: ";
    playlist.display();

    playlist.reverse();

    cout << "Reversed Playlist: ";
    playlist.display();

    return 0;
}
/*
- Implements singly linked list to represent a music playlist.
- Add new song at the end of the playlist.
- Reverse the playlist in-place using O(1) extra space.
- Display the playlist before and after reversal.
- Handles empty playlist scenario gracefully.
*/


