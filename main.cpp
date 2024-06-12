#include <iostream>
#include <string>
using namespace std;

// Room class
class Room {
private:
    int roomNumber;
    bool occupied;
    Room* nextRoom;
public:
    Room(int number) : roomNumber(number), occupied(false), nextRoom(nullptr) {}
    int getRoomNumber() { return roomNumber; }
    bool isOccupied() { return occupied; }
    void occupy() { occupied = true; }
    void vacate() { occupied = false; }
    Room* getNextRoom() { return nextRoom; }
    void setNextRoom(Room* next) { nextRoom = next; }
};

// Guest class
class Guest {
private:
    string name;
    int roomNumber;
    Guest* nextGuest;
public:
    Guest(string n, int room) : name(n), roomNumber(room), nextGuest(nullptr) {}
    string getName() { return name; }
    int getRoomNumber() { return roomNumber; }
    Guest* getNextGuest() { return nextGuest; }
    void setNextGuest(Guest* next) { nextGuest = next; }
};

// Hotel class
class Hotel {
private:
    Room* roomsHead;
    Guest* guestsHead;
public:
    Hotel(int numRooms) : roomsHead(nullptr), guestsHead(nullptr) {
        for (int i = 1; i <= numRooms; i++) {
            addRoom(i);
        }
    }

    void checkIn(string name, int roomNumber) {
        Room* room = findRoom(roomNumber);
        if (room == nullptr || room->isOccupied()) {
            cout << "Unable to check in guest " << name << endl;
            return;
        }
        Guest* guest = new Guest(name, roomNumber);
        guest->setNextGuest(guestsHead);
        guestsHead = guest;
        room->occupy();
        cout << "Guest " << name << " checked in to room " << roomNumber << endl;
    }

    void checkOut(int roomNumber) {
        Room* room = findRoom(roomNumber);
        if (room == nullptr || !room->isOccupied()) {
            cout << "Room " << roomNumber << " is not occupied" << endl;
            return;
        }

        Guest* prev = nullptr;
        Guest* curr = guestsHead;
        while (curr != nullptr && curr->getRoomNumber() != roomNumber) {
            prev = curr;
            curr = curr->getNextGuest();
        }
        if (curr != nullptr) {
            if (prev == nullptr) {
                guestsHead = curr->getNextGuest();
            } else {
                prev->setNextGuest(curr->getNextGuest());
            }
            delete curr;
            room->vacate();
            cout << "Guest checked out of room " << roomNumber << endl;
        }
    }

    void displayRooms() {
        cout << "Rooms:" << endl;
        Room* current = roomsHead;
        while (current != nullptr) {
            cout << "Room " << current->getRoomNumber() << ": " << (current->isOccupied() ? "Occupied" : "Vacant") << endl;
            current = current->getNextRoom();
        }
    }

private:
    void addRoom(int roomNumber) {
        Room* newRoom = new Room(roomNumber);
        newRoom->setNextRoom(roomsHead);
        roomsHead = newRoom;
    }

    Room* findRoom(int roomNumber) {
        Room* current = roomsHead;
        while (current != nullptr) {
            if (current->getRoomNumber() == roomNumber) {
                return current;
            }
            current = current->getNextRoom();
        }
        return nullptr;
    }
};

int main() {
    Hotel hotel(50);

    int choice;
    do {
        cout << "Hotel Management System" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Welcome to our Hotel!" << endl;
        cout << "What do you like to do?" << endl;
        cout << "1. Check In" << endl;
        cout << "2. Check Out" << endl;
        cout << "3. Display Rooms" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int room;
                cout << "Enter the guest name: ";
                cin >> name;
                cout << "Enter the room number: ";
                cin >> room;
                hotel.checkIn(name, room);
                break;
            }
            case 2: {
                int room;
                cout << "Enter the room number: ";
                cin >> room;
                hotel.checkOut(room);
                break;
            }
            case 3:
                hotel.displayRooms();
                break;
            case 4:
                cout << "Exiting..." << endl;
                cout << "Thanks for coming, visit again!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
