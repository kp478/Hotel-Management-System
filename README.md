# Hotel Management System in C++

This C++ mini project is a simple Hotel Management System that demonstrates the basic functionalities of managing rooms and guests in a hotel. It allows users to:

- **Check In**: Add a guest to a specified room, provided the room is available.
- **Check Out**: Remove a guest from a specified room, making the room available again.
- **Display Rooms**: View the status of all rooms, showing whether they are occupied or vacant.

The system uses three main classes: `Room`, `Guest`, and `Hotel`. The `Hotel` class manages a linked list of rooms and guests, providing methods to add rooms, check in guests, check out guests, and display the current room statuses. 

## Features:
- **Room Management**: Track room numbers and their occupancy status.
- **Guest Management**: Track guest names and their assigned room numbers.
- **Dynamic Data Structures**: Use of linked lists to manage rooms and guests efficiently.

## Usage:
- Compile and run the program.
- Follow the menu options to check in guests, check out guests, or display the room statuses.
- The system ensures that rooms are not double-booked and that guests can only check out from occupied rooms.

## How to Run:
1. Clone the repository.
    ```sh
    git clone https://github.com/yourusername/hotel-management-system.git
    ```
2. Navigate to the project directory.
    ```sh
    cd hotel-management-system
    ```
3. Compile the code using a C++ compiler.
    ```sh
    g++ HotelManagement.cpp -o HotelManagement
    ```
4. Run the executable.
    ```sh
    ./HotelManagement
    ```

## Example Usage:
```plaintext
Hotel Management System
---------------------------------------
Welcome to our Hotel!
What do you like to do?
1. Check In
2. Check Out
3. Display Rooms
4. Exit
Enter your choice: 1
Enter the guest name: John
Enter the room number: 5
Guest John checked in to room 5
