/*
9. Playlist Manager
Scenario:
You're designing a music app where each playlist is stored as a singly linked list.
Each node in the linked list represents a song, storing:
The song's name
A pointer to the next song
You need to implement basic playlist operations:
Add song at the end
Delete song by name
Display all songs
Problem:
Write a program to manage a playlist using a singly linked list with the above
operations.
Constraints:
1 number of songs
Song names S 50 characters (no special restrictions other than normal strings).
*/

// Q9: Playlist Manager using Singly Linked List
// Language: C++
#include <iostream>
#include <string>
using namespace std;
struct Song {
    string name;
    Song* next;
    Song(string songName) {
        name = songName;
        next = nullptr;
    }
};
class Playlist {
private:
    Song* head;

public:
    Playlist() {
        head = nullptr;
    }
    void addSong(string songName) {
        Song* newSong = new Song(songName);
        if (head == nullptr) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        cout << "Song added: " << songName << endl;
    }
    void deleteSong(string songName) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        if (head->name == songName) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << "Song deleted: " << songName << endl;
            return;
        }

        Song* current = head;
        Song* prev = nullptr;
        while (current != nullptr && current->name != songName) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Song not found.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Song deleted: " << songName << endl;
    }
    void displaySongs() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        Song* temp = head;
        cout << "Playlist:\n";
        while (temp != nullptr) {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist playlist;
    int choice;
    string songName;

    do {
        cout << "\n--- Playlist Manager ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Songs\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, songName);
                playlist.addSong(songName);
                break;
            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, songName);
                playlist.deleteSong(songName);
                break;
            case 3:
                playlist.displaySongs();
                break;
            case 4:
                cout << "Exiting Playlist Manager.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
/*
Features:
- Uses singly linked list for storage.
- Add song at end.
- Delete song by name.
- Display all songs.
- Handles empty playlist & song not found cases.
*/
