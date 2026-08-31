#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
using namespace std;

class Booking
{
private:
    int bookingID;
    int passengerID;
    int flightNumber;
    string seat;
    double price;

public:
    Booking(int bID, int pID, int fID, string s, double p);

    void display();

    int getBookingID();
    int getPassengerID();
    int getFlightNumber();
    string getSeat();
    double getPrice();
};

#endif