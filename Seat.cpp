#include "Seat.h"
#include <iostream>
using namespace std;

Seat::Seat(string number, string type) {
    seatNumber = number;
    seatClass = type;
    booked = false;
}

string Seat::getSeatNumber() const {
    return seatNumber;
}

string Seat::getSeatClass() const {
    return seatClass;
}

bool Seat::isBooked() const {
    return booked;
}

void Seat::bookSeat() {
    booked = true;
}

void Seat::cancelSeat() {
    booked = false;
}

void Seat::displaySeat() const {
    cout << seatNumber << " - "
         << seatClass << " - ";

    if (booked)
        cout << "Booked";
    else
        cout << "Available";

    cout << endl;
}
