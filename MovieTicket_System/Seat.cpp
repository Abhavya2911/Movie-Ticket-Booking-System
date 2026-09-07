#include <iostream>
#include <string>
using namespace std;

class Seat {
private:
    string number;
    string type;
    double price;

public:
    Seat(string n, string t) {
        number = n;
        type = t;

        if (type == "SILVER")
            price = 150;
        else if (type == "GOLD")
            price = 250;
        else
            price = 400;
    }

    string getNumber() {
        return number;
    }

    string getType() {
        return type;
    }

    double getPrice() {
        return price;
    }
};