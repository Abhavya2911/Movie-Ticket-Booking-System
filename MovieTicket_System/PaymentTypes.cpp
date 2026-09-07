#include <iostream>
using namespace std;

// Inheritance and Runtime Polymorphism

class UpiPayment : public Payment {
public:
    bool pay(double amount) {
        int choice;

        cout << "UPI Payment: Rs." << amount << endl;
        cout << "Enter 1 for successful payment, 0 for failed: ";
        cin >> choice;

        return choice == 1;
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) {
        int choice;

        cout << "Card Payment: Rs." << amount << endl;
        cout << "Enter 1 for successful payment, 0 for failed: ";
        cin >> choice;

        return choice == 1;
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) {
        int choice;

        cout << "Cash Payment: Rs." << amount << endl;
        cout << "Enter 1 for successful payment, 0 for failed: ";
        cin >> choice;

        return choice == 1;
    }
};