#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string language;
    int duration;

public:
    Movie(string t, string l, int d) {
        title = t;
        language = l;
        duration = d;
    }

    string getTitle() {
        return title;
    }

    string getLanguage() {
        return language;
    }

    int getDuration() {
        return duration;
    }
};