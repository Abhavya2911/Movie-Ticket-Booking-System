#include <iostream>
using namespace std;

class TicketPrinter {
public:
    void printTicket(Booking* booking) {
        Show* show = booking->getShow();

        cout << "\n====================================\n";
        cout << "             TICKET\n";
        cout << "====================================\n";

        cout << "Booking ID : " << booking->getBookingId() << endl;
        cout << "Movie      : " << show->getMovie()->getTitle() << endl;
        cout << "Screen     : Screen-" 
             << show->getScreen()->getScreenNumber() << endl;
        cout << "Time       : " << show->getStartTime() << endl;

        cout << "Seats      : ";

        vector<ShowSeat*>& seats = booking->getSeats();

        for (int i = 0; i < seats.size(); i++)
            cout << seats[i]->getSeat()->getNumber() << " ";

        cout << endl;

        cout << "Amount     : Rs." << booking->getTotalAmount() << endl;
        cout << "Status     : " << booking->getStatus() << endl;

        cout << "====================================\n";
    }
};