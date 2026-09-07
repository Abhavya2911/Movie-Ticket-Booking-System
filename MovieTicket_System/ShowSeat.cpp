#include <iostream>
#include <string>
using namespace std;

class ShowSeat {
private:
    Seat* seat;
    string status;

public:
    ShowSeat(Seat* s) {
        seat = s;
        status = "AVAILABLE";
    }

    Seat* getSeat() {
        return seat;
    }

    bool isAvailable() {
        return status == "AVAILABLE";
    }

    string getStatus() {
        return status;
    }

    void book() {
        status = "BOOKED";
    }

    void release() {
        status = "AVAILABLE";
    }
};