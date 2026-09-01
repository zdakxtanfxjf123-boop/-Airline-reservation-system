#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "Seat.h"

using namespace std;

class Flight {
private:
    int flightNumber;
    string source;
    string destination;
    string date;
    string time;
    int capacity;
    vector<vector<Seat>> seats;
    int columns;

public:
    Flight(int flightNumber, string source, string destination,
           string date, string time, int capacity);

    int getFlightNumber() const;

    void displayFlight() const;
    void displaySeats() const;

    bool isFlightFull() const;

    void bookSeat(const string& seatNumber);
    void cancelSeat(const string& seatNumber);
    bool isSeatAvailable(const std::string& seatNumber) const;
    string getSeatClass(const std::string& seatNumber) const;
};

#endif
