#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "PaymentTypes.cpp"
#include "Booking.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int main() {

    cout << "===== MOVIE TICKET BOOKING =====\n";

    // Creating cinema
    Cinema cinema("PVR Cinema");

    // Creating screen
    Screen screen1(1);

    screen1.addSeat(Seat("A1", "SILVER"));
    screen1.addSeat(Seat("A2", "SILVER"));
    screen1.addSeat(Seat("B1", "GOLD"));
    screen1.addSeat(Seat("B2", "GOLD"));
    screen1.addSeat(Seat("C1", "PLATINUM"));
    screen1.addSeat(Seat("C2", "PLATINUM"));

    cinema.addScreen(screen1);

    // Movies
    Movie movie1("Spider-Man:Brand New Day", "English", 145);
    Movie movie2("Dhurandhar", "Hindi", 235);

    // Shows
    Show show1(
        &movie1,
        &cinema.getScreens()[0],
        "05:00 PM"
    );

    Show show2(
        &movie1,
        &cinema.getScreens()[0],
        "11:00 PM"
    );

    Customer customer("Abhavya Dobhal", "9999999999");

    BookingService service;

    Booking* lastBooking = NULL;

    int choice;

    do {

        cout << "\n1. Movies";
        cout << "\n2. Shows";
        cout << "\n3. Book Ticket";
        cout << "\n4. Cancel Booking";
        cout << "\n0. Exit";

        cout << "\nChoose: ";
        cin >> choice;

        if (choice == 1) {

            cout << "\nMovies Playing:\n";

            cout << "[1] "
                 << movie1.getTitle()
                 << " - "
                 << movie1.getLanguage()
                 << " - "
                 << movie1.getDuration()
                 << " min\n";

            cout << "[2] "
                 << movie2.getTitle()
                 << " - "
                 << movie2.getLanguage()
                 << " - "
                 << movie2.getDuration()
                 << " min\n";
        }

        else if (choice == 2) {

            cout << "\nShows:\n";

            cout << "[1] Screen-"
                 << show1.getScreen()->getScreenNumber()
                 << " - "
                 << show1.getStartTime()
                 << endl;

            cout << "[2] Screen-"
                 << show2.getScreen()->getScreenNumber()
                 << " - "
                 << show2.getStartTime()
                 << endl;
        }

        else if (choice == 3) {

            int showChoice;

            cout << "\nChoose Show:\n";
            cout << "1. 05:00 PM\n";
            cout << "2. 11:00 PM\n";
            cout << "Choose: ";
            cin >> showChoice;

            Show* selectedShow;

            if (showChoice == 1)
                selectedShow = &show1;
            else if (showChoice == 2)
                selectedShow = &show2;
            else {
                cout << "Invalid show.\n";
                continue;
            }

            cout << "\nSeats:\n";
            selectedShow->showSeatsLayout();

            int numberOfSeats;

            cout << "\nHow many seats? ";
            cin >> numberOfSeats;

            vector<string> seatNumbers;

            for (int i = 0; i < numberOfSeats; i++) {

                string seat;

                cout << "Enter seat " << i + 1 << ": ";
                cin >> seat;

                seatNumbers.push_back(seat);
            }

            cout << "\n1. UPI";
            cout << "\n2. Card";
            cout << "\n3. Cash";

            int paymentChoice;

            cout << "\nChoose payment: ";
            cin >> paymentChoice;

            Payment* payment = NULL;

            if (paymentChoice == 1)
                payment = new UpiPayment();

            else if (paymentChoice == 2)
                payment = new CardPayment();

            else if (paymentChoice == 3)
                payment = new CashPayment();

            else {
                cout << "Invalid payment.\n";
                continue;
            }

            lastBooking = service.bookTicket(
                &customer,
                selectedShow,
                seatNumbers,
                payment
            );

            delete payment;
        }

        else if (choice == 4) {

            string id;

            cout << "Enter Booking ID: ";
            cin >> id;

            service.cancelBooking(id);
        }

        else if (choice == 0) {
            cout << "\nThank you!\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}