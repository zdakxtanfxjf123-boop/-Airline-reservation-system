#include "Booking.h"

Booking::Booking(int bID, int pID, int fID, string s, double p)
{
    bookingID = bID;
    passengerID = pID;
    flightNumber = fID;
    seat = s;
    price = p;
}

void Booking::display()
{
    cout << "\n===== Booking =====" << endl;

    cout << "Booking ID: " << bookingID << endl;
    cout << "Passenger ID: " << passengerID << endl;
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Seat: " << seat << endl;
    cout << "Price: " << price << endl;
}

int Booking::getBookingID()
{
    return bookingID;
}

int Booking::getPassengerID()
{
    return passengerID;
}

int Booking::getFlightNumber()
{
    return flightNumber;
}

string Booking::getSeat()
{
    return seat;
}

double Booking::getPrice()
{
    return price;
}