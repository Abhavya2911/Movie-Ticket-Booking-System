#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phone;

public:
    Customer(string n, string p) {
        name = n;
        phone = p;
    }

    string getName() {
        return name;
    }

    string getPhone() {
        return phone;
    }
};