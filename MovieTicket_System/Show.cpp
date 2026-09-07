#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Show {
private:
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(Movie* m, Screen* s, string time) {
        movie = m;
        screen = s;
        startTime = time;

        for (int i = 0; i < s->getSeats().size(); i++) {
            showSeats.push_back(ShowSeat(&s->getSeats()[i]));
        }
    }

    Movie* getMovie() {
        return movie;
    }

    Screen* getScreen() {
        return screen;
    }

    string getStartTime() {
        return startTime;
    }

    vector<ShowSeat>& getShowSeats() {
        return showSeats;
    }

    ShowSeat* findSeat(string number) {
        for (int i = 0; i < showSeats.size(); i++) {
            if (showSeats[i].getSeat()->getNumber() == number)
                return &showSeats[i];
        }

        return NULL;
    }

    void showSeatsLayout() {
        for (int i = 0; i < showSeats.size(); i++) {
            cout << showSeats[i].getSeat()->getNumber();

            if (showSeats[i].isAvailable())
                cout << "[ ] ";
            else
                cout << "[X] ";
        }

        cout << endl;
    }
};