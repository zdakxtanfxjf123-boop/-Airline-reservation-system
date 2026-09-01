
#include "Flight.h"
#include <iostream>

using namespace std;

Flight::Flight(int flightNumber, string source, string destination,
               string date, string time, int capacity) {

    this->flightNumber = flightNumber;
    this->source = source;
    this->destination = destination;
    this->date = date;
    this->time = time;
    this->capacity = capacity;

    columns = 4;

    int rows = (capacity + columns - 1) / columns;
   
    seats.resize(rows);

    for (int i = 0; i < rows; i++) {
        seats[i].resize(columns);
        for (int j = 0; j < columns; j++) {

            string number =
                string(1, char('A' + i)) + to_string(j + 1);

            if (i == 0)
                seats[i][j] = Seat(number, "First");
            else if (i == 1)
                seats[i][j] = Seat(number, "Business");
            else
                seats[i][j] = Seat(number, "Economy");
        }
    }
}

int Flight::getFlightNumber() const {
    return flightNumber;
}

void Flight::displayFlight() const {

    cout << "Flight Number: " << flightNumber << endl;
    cout << "From: " << source << endl;
    cout << "To: " << destination << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Capacity: " << capacity << endl;
}

void Flight::displaySeats() const {

    cout << "\nSeat Map\n";

    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {
            seats[i][j].displaySeat();
        }
    }
}

bool Flight::isFlightFull() const {

    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {

            if (!seats[i][j].isBooked())
                return false;
        }
    }

    return true;
}

void Flight::bookSeat(const string& seatNumber) {

    if (isFlightFull()) {
        cout << "Flight is fully booked. Cannot book more seats\n";
        return;
    }

    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {

            if (seats[i][j].getSeatNumber() == seatNumber) {

                if (seats[i][j].isBooked()) {
                    cout << "Seat is already booked\n";
                    return;
                }

                seats[i][j].bookSeat();

                cout << "Seat booked successfully\n";
                return;
            }
        }
    }

    cout << "Seat not found\n";
}

void Flight::cancelSeat(const string& seatNumber) {

    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {

            if (seats[i][j].getSeatNumber() == seatNumber) {

                if (!seats[i][j].isBooked()) {
                    cout << "Seat is not booked\n";
                    return;
                }

                seats[i][j].cancelSeat();

                cout << "Seat booking cancelled successfully\n";
                return;
            }
        }
    }

    cout << "Seat not found\n";
}
bool Flight::isSeatAvailable(const string& seatNumber) const {
    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {
            if (seats[i][j].getSeatNumber() == seatNumber) {
                return !seats[i][j].isBooked();
            }
        }
    }
    return false;
}

string Flight::getSeatClass(const string& seatNumber) const {
    for (int i = 0; i < seats.size(); i++) {
        for (int j = 0; j < seats[i].size(); j++) {
            if (seats[i][j].getSeatNumber() == seatNumber) {
                return seats[i][j].getSeatClass();
            }
        }
    }
    return "";
}
