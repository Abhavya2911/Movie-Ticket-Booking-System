#include <iostream>
#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int n) {
        screenNumber = n;
    }

    void addSeat(Seat seat) {
        seats.push_back(seat);
    }

    int getScreenNumber() {
        return screenNumber;
    }

    vector<Seat>& getSeats() {
        return seats;
    }
};