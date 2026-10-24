#include <iostream>
#include <string>

using namespace std;

// Node for one song
class Node {
public:
    string title;
    string artist;
    Node *prev, *next;
    Node(string t, string a) {
        title = t;
        artist = a;
        prev = next = NULL;
    }
};

class Playlist {
    Node *head;
    Node *current;
public:
    Playlist() {
        head = NULL;
        current = NULL;
    }

    // Add song
    void addSong(string title, string artist) {
        Node *p = new Node(title, artist);
        if (head == NULL) {
            head = p;
            current = p;
        } else {
            Node *q = head;
            while (q->next != NULL) q = q->next;
            q->next = p;
            p->prev = q;
        }
        cout << "Song added.\n";
    }

    // Delete song
    void deleteSong(string title) {
        Node *q = head;
        while (q != NULL && q->title != title) q = q->next;
        if (q == NULL) {
            cout << "Song not found.\n";
            return;
        }
        Node *p = q;
        if (p->prev != NULL) p->prev->next = p->next;
        else head = p->next;
        
        if (p->next != NULL) p->next->prev = p->prev;
        
        if (current == p) current = (p->next != NULL) ? p->next : p->prev;
        delete p;
        cout << "Song deleted.\n";
    }

    // Display forward
    void display() {
        Node *q = head;
        if (q == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }
        while (q != NULL) {
            cout << q->title << " - " << q->artist;
            if (q == current) cout << " <- Current";
            cout << endl;
            q = q->next;
        }
    }

    // Display reverse
    void reverseDisplay() {
        Node *q = head;
        if (q == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }
        while (q->next != NULL) q = q->next;
        while (q != NULL) {
            cout << q->title << " - " << q->artist << endl;
            q = q->prev;
        }
    }

    // Play current song
    void playCurrent() {
        if (current == NULL) cout << "Playlist is empty.\n";
        else cout << "Playing: " << current->title << " - " << current->artist << endl;
    }

    // Next song
    void nextSong() {
        if (current != NULL && current->next != NULL) current = current->next;
        else cout << "No next song.\n";
    }

    // Previous song
    void previousSong() {
        if (current != NULL && current->prev != NULL) current = current->prev;
        else cout << "No previous song.\n";
    }
};

int main() {
    Playlist p;
    int choice;
    string title, artist;
    
    do {
        cout << "\n--- MUSIC PLAYLIST ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Reverse Display\n";
        cout << "5. Play Current Song\n";
        cout << "6. Next Song\n";
        cout << "7. Previous Song\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        
        
        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a valid number.\n";
            cin.clear();              
            cin.ignore(10000, '\n');  
            continue;                 
        }
        
        
        cin.ignore(10000, '\n'); 

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);  
                cout << "Enter artist name: ";
                getline(cin, artist); 
                p.addSong(title, artist);
                break;
            case 2:
                cout << "Enter song title to delete: ";
                getline(cin, title);
                p.deleteSong(title);
                break;
            case 3:
                p.display();
                break;
            case 4:
                p.reverseDisplay();
                break;
            case 5:
                p.playCurrent();
                break;
            case 6:
                p.nextSong();
                break;
            case 7:
                p.previousSong();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please select from options 1-8.\n";
        }
    } while (choice != 8);
    
    return 0;
}
// --- MUSIC PLAYLIST ---
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Reverse Display
// 5. Play Current Song
// 6. Next Song
// 7. Previous Song
// 8. Exit
// Enter choice: 1
// Enter song title: lover
// Enter artist name: taylor swift
// Song added.

// --- MUSIC PLAYLIST ---
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Reverse Display
// 5. Play Current Song
// 6. Next Song
// 7. Previous Song
// 8. Exit
// Enter choice: 3
// lover - taylor swift <- Current

// --- MUSIC PLAYLIST ---
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Reverse Display
// 5. Play Current Song
// 6. Next Song
// 7. Previous Song
// 8. Exit
// Enter choice: baby   
// Invalid choice. Please enter a valid number.

// --- MUSIC PLAYLIST ---
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Reverse Display
// 5. Play Current Song
// 6. Next Song
// 7. Previous Song
// 8. Exit
// Enter choice: 1
// Enter song title: baby
// Enter artist name: justine bieber
// Song added.

// --- MUSIC PLAYLIST ---
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Reverse Display
// 5. Play Current Song
// 6. Next Song
// 7. Previous Song
// 8. Exit
// Enter choice: 