#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Booking {
private:
    static int nextBookingId;

    string bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    string status;

public:
    Booking(Customer* c, Show* s) {
        customer = c;
        show = s;
        totalAmount = 0;
        status = "PENDING";

        bookingId = "BK" + to_string(nextBookingId);
        nextBookingId++;
    }

    void addSeat(ShowSeat* seat) {
        seats.push_back(seat);
    }

    void setTotalAmount(double amount) {
        totalAmount = amount;
    }

    void confirm() {
        status = "CONFIRMED";
    }

    void cancel() {
        status = "CANCELLED";

        for (int i = 0; i < seats.size(); i++)
            seats[i]->release();
    }

    string getBookingId() {
        return bookingId;
    }

    string getStatus() {
        return status;
    }

    double getTotalAmount() {
        return totalAmount;
    }

    Show* getShow() {
        return show;
    }

    vector<ShowSeat*>& getSeats() {
        return seats;
    }
};

// Static member
int Booking::nextBookingId = 1001;