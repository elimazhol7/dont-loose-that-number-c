#include "rolodex.h"
#include <iostream>
using namespace std;

int main() {
    rolodex myRolodex;
    int choice;

    do {
        cout << "\n1) Add  2) Edit  3) Delete  4) Find  5) Print  6) Quit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {  // Add
            char n[50], a[100], p[20], e[50];
            cout << "Name: "; cin.getline(n, 50);
            cout << "Address: "; cin.getline(a, 100);
            cout << "Phone: "; cin.getline(p, 20);
            cout << "Email: "; cin.getline(e, 50);
            rolodexEntry entry(n, a, p, e);
            if (!myRolodex.add(entry)) cout << "Rolodex full!\n";
        }
        else if (choice == 2) {  // Edit
            myRolodex.printAll();
            cout << "Enter index to edit: ";
            size_t idx; cin >> idx; cin.ignore();
            if (idx == 0 || idx > myRolodex.size()) {
                cout << "Invalid index.\n";
                continue;
            }
            char n[50], a[100], p[20], e[50];
            cout << "New Name: "; cin.getline(n, 50);
            cout << "New Address: "; cin.getline(a, 100);
            cout << "New Phone: "; cin.getline(p, 20);
            cout << "New Email: "; cin.getline(e, 50);
            rolodexEntry entry(n, a, p, e);
            if (!myRolodex.edit(idx - 1, entry)) cout << "Edit failed.\n";
        }
        else if (choice == 3) {  // Delete
            myRolodex.printAll();
            cout << "Enter index to delete: ";
            size_t idx; cin >> idx; cin.ignore();
            if (!myRolodex.remove(idx - 1)) cout << "Delete failed.\n";
        }
        else if (choice == 4) {  // Find
            int fchoice;
            cout << "\nFind by:\n1) Name\n2) Address\n3) Phone\n4) Email\n5) Return\nChoice: ";
            cin >> fchoice; cin.ignore();

            char search[100];
            if (fchoice >= 1 && fchoice <= 4) {
                cout << "Enter search term: ";
                cin.getline(search, 100);
            }

            int result = -1;
            switch (fchoice) {
                case 1: result = myRolodex.findByName(search); break;
                case 2: result = myRolodex.findByAddress(search); break;
                case 3: result = myRolodex.findByPhone(search); break;
                case 4: result = myRolodex.findByEmail(search); break;
                default: break;
            }

            if (result >= 0) {
                cout << "Found entry:\n";
                myRolodex.get(result).print();
            } else if (fchoice >= 1 && fchoice <= 4) {
                cout << "No match found.\n";
            }
        }
        else if (choice == 5) {  // Print
            myRolodex.printAll();
        }

    } while (choice != 6);

    return 0;
}
