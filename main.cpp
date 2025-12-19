#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// User database (username -> password)
unordered_map<string, string> userDatabase;

// Generate OTP
int generateOTP() {
    srand(time(0));
    return 100000 + rand() % 900000; // 6-digit OTP
}

// Register new user
void registerUser() {
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter Username: ";
    cin >> username;

    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "User already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    userDatabase[username] = password;
    cout << "Registration successful.\n";
}

// Login with OTP verification
void loginUser() {
    string username, password;

    cout << "\n--- User Login ---\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (userDatabase.find(username) != userDatabase.end() &&
        userDatabase[username] == password) {

        int otp = generateOTP();
        int enteredOTP;

        cout << "OTP Generated: " << otp << endl;
        cout << "Enter OTP: ";
        cin >> enteredOTP;

        if (enteredOTP == otp) {
            cout << "Login successful. Access granted.\n";
        } else {
            cout << "Invalid OTP. Access denied.\n";
        }

    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;

    cout << "========================================\n";
    cout << " Secure Authentication System (OS)\n";
    cout << "========================================\n";
    cout << "1. Register User\n";
    cout << "2. Login User\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "System exiting.\n";
            break;
        default:
            cout << "Invalid selection.\n";
    }

    return 0;
}
