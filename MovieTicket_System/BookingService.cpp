#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    vector<Booking*> bookings;

public:
    Booking* bookTicket(Customer* customer, Show* show,
                        vector<string> seatNumbers,
                        Payment* payment) {

        vector<ShowSeat*> selectedSeats;

        // Check all seats first
        for (int i = 0; i < seatNumbers.size(); i++) {

            ShowSeat* seat = show->findSeat(seatNumbers[i]);

            if (seat == NULL) {
                cout << "Invalid seat: " << seatNumbers[i] << endl;
                return NULL;
            }

            if (!seat->isAvailable()) {
                cout << "Seat " << seatNumbers[i]
                     << " is already BOOKED.\n";
                return NULL;
            }

            selectedSeats.push_back(seat);
        }

        Booking* booking = new Booking(customer, show);

        for (int i = 0; i < selectedSeats.size(); i++)
            booking->addSeat(selectedSeats[i]);

        double total =
            priceCalculator.calculateTotal(selectedSeats);

        booking->setTotalAmount(total);

        cout << "\nTotal Amount: Rs." << total << endl;

        bool paid = payment->pay(total);

        if (!paid) {
            cout << "Payment failed.\n";

            // Release seats
            for (int i = 0; i < selectedSeats.size(); i++)
                selectedSeats[i]->release();

            delete booking;

            cout << "Booking NOT confirmed.\n";
            return NULL;
        }

        for (int i = 0; i < selectedSeats.size(); i++)
            selectedSeats[i]->book();

        booking->confirm();
        bookings.push_back(booking);

        cout << "Payment successful.\n";
        cout << "Booking confirmed.\n";

        ticketPrinter.printTicket(booking);

        return booking;
    }

    void cancelBooking(string id) {

        for (int i = 0; i < bookings.size(); i++) {

            if (bookings[i]->getBookingId() == id) {

                if (bookings[i]->getStatus() == "CONFIRMED") {
                    bookings[i]->cancel();

                    cout << "Booking cancelled.\n";
                    cout << "Seats are AVAILABLE again.\n";
                }
                else {
                    cout << "Booking cannot be cancelled.\n";
                }

                return;
            }
        }

        cout << "Booking ID not found.\n";
    }
};