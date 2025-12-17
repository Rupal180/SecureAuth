#include <iostream>
using namespace std;

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

    cout << "\nYou selected option: " << choice << endl;

    return 0;
}
