#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <vector>
#include <iostream>
#include <string>

#include "PassengerManager.h"
#include "Flight.h"
#include "CrewManager.h"
#include "Pricing.h"
#include "Booking.h"
#include "WaitingList.h"
#include "Pilot.h"
#include "FlightAttendant.h"

class BookingSystem {
private:
    PassengerManager passengerManager;
    std::vector<Flight> flights;
    CrewManager crewManager;
    Pricing pricing;
    std::vector<Booking> bookings;
    WaitingList waitingList;
    int nextBookingId = 1;

    Flight* findFlight(int id);
    bool passengerHasBooking(int p, int f);

public:
    void addPassenger();
    void displayPassenger();
    void addFlight();
    void displayFlights();
    void bookTicket();
    void cancelBooking();
    void showBooking();
    void boardingPass();
    void addPilot();
    void addAttendant();
    void assignCrew();
    void displayCrew();
    void run();
};

#endif