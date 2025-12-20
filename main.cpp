/***************************************************************
 Project Title : Secure Authentication Module for OS
 Subject       : Operating Systems
 Description   :
 This program simulates a secure authentication mechanism
 used in operating systems. It includes user registration,
 login authentication with OTP, session management,
 account lockout and security audit logging.
***************************************************************/

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

/* ================= GLOBAL CONSTANTS ================= */

#define MAX_FAILED_ATTEMPTS 3

/* ================= USER STRUCTURE ================= */

struct User {
    string username;
    string password;
    int failedAttempts;
    bool isLocked;
};

/* ================= GLOBAL STATE ================= */

unordered_map<string, User> userDatabase;
bool isSessionActive = false;
string loggedInUser;

/* ================= UTILITY FUNCTIONS ================= */

// Get current system time
string getSystemTime() {
    time_t now = time(0);
    return ctime(&now);
}

// Write security logs
void writeSecurityLog(const string &message) {
    ofstream logFile("auth_audit_log.txt", ios::app);
    logFile << "[" << getSystemTime() << "] " << message << endl;
    logFile.close();
}

// Generate OTP
int generateOTP() {
    srand(time(0));
    return 100000 + rand() % 900000;
}

/* ================= REGISTRATION MODULE ================= */

void registerUser() {
    User newUser;

    cout << "\n--- USER REGISTRATION ---\n";
    cout << "Enter Username: ";
    cin >> newUser.username;

    if (userDatabase.find(newUser.username) != userDatabase.end()) {
        cout << "User already exists.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> newUser.password;

    newUser.failedAttempts = 0;
    newUser.isLocked = false;

    userDatabase[newUser.username] = newUser;
    writeSecurityLog("New user registered: " + newUser.username);

    cout << "Registration successful.\n";
}

/* ================= LOGIN + OTP MODULE ================= */

bool loginUser() {
    string username, password;

    cout << "\n--- USER LOGIN ---\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (userDatabase.find(username) == userDatabase.end()) {
        cout << "Invalid username.\n";
        return false;
    }

    User &u = userDatabase[username];

    if (u.isLocked) {
        cout << "Account is locked.\n";
        return false;
    }

    if (u.password == password) {
        int otp = generateOTP();
        int enteredOTP;

        cout << "OTP Generated: " << otp << endl;
        cout << "Enter OTP: ";
        cin >> enteredOTP;

        if (enteredOTP != otp) {
            cout << "OTP verification failed.\n";
            writeSecurityLog("OTP failure for user: " + username);
            return false;
        }

        u.failedAttempts = 0;
        isSessionActive = true;
        loggedInUser = username;

        writeSecurityLog("Login successful: " + username);
        cout << "Login successful.\n";
        return true;
    }

    u.failedAttempts++;
    writeSecurityLog("Failed login attempt: " + username);

    if (u.failedAttempts >= MAX_FAILED_ATTEMPTS) {
        u.isLocked = true;
        writeSecurityLog("Account locked: " + username);
        cout << "Account locked due to multiple failures.\n";
    } else {
        cout << "Incorrect password.\n";
    }

    return false;
}

/* ================= SESSION MANAGEMENT ================= */

void showSessionInfo() {
    cout << "\n--- SESSION INFO ---\n";
    cout << "Logged-in User: " << loggedInUser << endl;
    cout << "Login Time: " << getSystemTime() << endl;
}

void secureLogout() {
    cout << "\nLogging out";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(1000);
    }

    writeSecurityLog("User logged out: " + loggedInUser);
    isSessionActive = false;
    loggedInUser = "";

    cout << "\nLogout successful.\n";
}

/* ================= USER DASHBOARD ================= */

void userDashboard() {
    int choice;

    while (isSessionActive) {
        cout << "\n--- USER DASHBOARD ---\n";
        cout << "1. View Session Info\n";
        cout << "2. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showSessionInfo();
                break;
            case 2:
                secureLogout();
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
}

/* ================= MAIN ================= */

int main() {
    int choice;

    while (true) {
        cout << "\n========================================\n";
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
                if (loginUser())
                    userDashboard();
                break;
            case 3:
                cout << "System terminated.\n";
                return 0;
            default:
                cout << "Invalid selection.\n";
        }
    }
}

