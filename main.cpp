#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// User database (username -> password)
unordered_map<string, string> userDatabase;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter Username: ";
    cin >> username;

    // Check if user already exists
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "User already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    userDatabase[username] = password;
    cout << "Registration successful.\n";
}

int main() {
    int choice;

    cout << "========================================\n";
    cout << " Secure Authentication System (OS)\n";
    cout << "========================================\n";
    cout << "1. Register User\n";
    cout << "2. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            cout << "Exiting system.\n";
            break;
        default:
            cout << "Invalid option.\n";
    }

    return 0;
}
