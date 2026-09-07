#include <iostream>
#include <vector>
using namespace std;

class PriceCalculator {
public:
    double calculateTotal(vector<ShowSeat*> seats) {
        double total = 0;

        for (int i = 0; i < seats.size(); i++) {
            total = total + seats[i]->getSeat()->getPrice();
        }

        return total;
    }
};