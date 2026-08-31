#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <iostream>
#include <vector>
#include "Booking.h"
#include "WaitingList.h"
using namespace std;

class BookingSystem
{
private:
    vector<Booking> bookings;
    WaitingList waitingList;
    int nextBookingID;

public:
    BookingSystem();
    void run();
    void addBooking(int passengerID,
                    int flightNumber,
                    string seat,
                    double price);

    void cancelBooking(int bookingID);

    void displayBookings();

    void addToWaitingList(int passengerID);

    void displayWaitingList();
};

#endif