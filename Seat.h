#ifndef SEAT_H
#define SEAT_H

#include <string>
using namespace std;

class Seat {
private:
    string seatNumber;
    string seatClass;
    bool booked;

public:
    Seat(string number = "", string type = "Economy");

    string getSeatNumber() const;
    string getSeatClass() const;
    bool isBooked() const;

    void bookSeat();
    void cancelSeat();
    void displaySeat() const;
};

#endif
