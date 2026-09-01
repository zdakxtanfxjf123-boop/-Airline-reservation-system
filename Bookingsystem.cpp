#include "BookingSystem.h"

Flight* BookingSystem::findFlight(int id)
{
    for (auto &f : flights)
    {
        if (f.getFlightNumber() == id) return &f;
    }
    return nullptr;
}

bool BookingSystem::passengerHasBooking(int p, int f)
{
    for (auto &b : bookings)
    {
        if (b.getPassengerID() == p && b.getFlightNumber() == f) return true;
    }
    return false;
}

void BookingSystem::addPassenger()
{
    passengerManager.add_passengarinfo();
}

void BookingSystem::displayPassenger()
{
    int id;
    cout << "Enter Passenger ID: ";
    cin >> id;
    passengerManager.display_passenger(id);
}

void BookingSystem::addFlight()
{
    int n, c;
    string s, d, da, t;
    cout << "Flight Number: ";
    cin >> n;
    cout << "Source: ";
    cin >> s;
    cout << "Destination: ";
    cin >> d;
    cout << "Date: ";
    cin >> da;
    cout << "Time: ";
    cin >> t;
    cout << "Capacity: ";
    cin >> c;
    flights.push_back(Flight(n, s, d, da, t, c));
}

void BookingSystem::displayFlights()
{
    for (auto &f : flights)
    {
        cout << "\n--------------------\n";
        f.displayFlight();
        f.displaySeats();
    }
}

void BookingSystem::bookTicket()
{
    int p, f;
    string seat;
    cout << "Passenger ID: ";
    cin >> p;
    if (!passengerManager.passenger_Exists(p))
    {
        cout << "Passenger not found.\n";
        return;
    }

    cout << "Flight ID: ";
    cin >> f;
    Flight* flight = findFlight(f);
    if (!flight)
    {
        cout << "Flight not found.\n";
        return;
    }

    if (passengerHasBooking(p, f))
    {
        cout << "Passenger already booked this flight.\n";
        return;
    }

    if (flight->isFlightFull())
    {
        if (!waitingList.hasPassenger(p, f))
            waitingList.addPassenger(p, f);
        else
            cout << "Passenger is already on waiting list.\n";
        return;
    }

    cout << "Seat: ";
    cin >> seat;
    if (!flight->isSeatAvailable(seat))
    {
        cout << "Seat is not available or not found.\n";
        return;
    }

    double price = pricing.getFinalPrice(flight->getSeatClass(seat), 100, 0);
    flight->bookSeat(seat);
    bookings.push_back(Booking(nextBookingId, p, f, seat, price));
    passengerManager.book_ticket_for_passenger(p, nextBookingId);

    cout << "Booking successful!\nBooking ID: " << nextBookingId
         << "\nFinal Price: " << price << endl;
    nextBookingId++;
}

void BookingSystem::cancelBooking()
{
    int id;
    cout << "Booking ID: ";
    cin >> id;

    for (int i = 0; i < bookings.size(); i++)
    {
        if (bookings[i].getBookingID() == id)
        {
            int p = bookings[i].getPassengerID();
            int f = bookings[i].getFlightNumber();
            string seat = bookings[i].getSeat();

            Flight* flight = findFlight(f);
            if (flight) flight->cancelSeat(seat);

            passengerManager.cancel_ticket_for_passenger(p, id);
            bookings.erase(bookings.begin() + i);
            cout << "Booking cancelled.\n";

            int wp = waitingList.getFirstPassenger(f);
            if (wp != -1 && flight)
            {
                waitingList.removeFirstPassenger(f);
                double price = pricing.getFinalPrice(flight->getSeatClass(seat), 100, 0);
                flight->bookSeat(seat);
                bookings.push_back(Booking(nextBookingId, wp, f, seat, price));
                passengerManager.book_ticket_for_passenger(wp, nextBookingId);

                cout << "Passenger " << wp << " moved from waiting list.\nNew Booking ID: " << nextBookingId << endl;
                nextBookingId++;
            }
            return;
        }
    }
    cout << "Booking not found.\n";
}

void BookingSystem::showBooking()
{
    int id;
    cout << "Booking ID: ";
    cin >> id;
    for (auto &b : bookings)
    {
        if (b.getBookingID() == id)
        {
            b.display();
            return;
        }
    }
    cout << "Booking not found.\n";
}
void BookingSystem::boardingPass()
{
    int id;
    cout << "Booking ID: ";
    cin >> id;
    for (auto &b : bookings)
    {
        if (b.getBookingID() == id)
        {
            string seat = b.getSeat();
            passengerManager.print_board_pass(b.getPassengerID(), seat);
            return;
        }
    }
    cout << "Booking not found.\n";
}
void BookingSystem::addPilot()
{
    int id;
    string n, l;
    cout << "Pilot ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> n;
    cout << "License: ";
    cin >> l;
    crewManager.addCrew(new Pilot(id, n, l));
}

void BookingSystem::addAttendant()
{
    int id;
    string n, l;
    cout << "Attendant ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> n;
    cout << "Language: ";
    cin >> l;
    crewManager.addCrew(new FlightAttendant(id, n, l));
}

void BookingSystem::assignCrew()
{
    int c, f;
    cout << "Crew ID: ";
    cin >> c;
    cout << "Flight ID: ";
    cin >> f;
    if (findFlight(f))
        crewManager.assignCrewToFlight(c, f);
    else
        cout << "Flight not found.\n";
}

void BookingSystem::displayCrew()
{
    int f;
    cout << "Flight ID: ";
    cin >> f;
    crewManager.displayCrewForFlight(f);
}

void BookingSystem::run()
{
    int ch;
    do
    {
        cout << "\n========== AIRLINE RESERVATION SYSTEM ==========\n";
        cout << "1 Add Passenger\n2 Display Passenger\n3 Add Flight\n4 Display Flights\n"
             << "5 Book Ticket\n6 Cancel Booking\n7 Show Booking\n8 Boarding Pass\n"
             << "9 Add Pilot\n10 Add Flight Attendant\n11 Assign Crew\n12 Display Crew\n"
             << "13 Display Waiting List\n0 Exit\nChoice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            addPassenger();
            break;
        case 2:
            displayPassenger();
            break;
        case 3:
            addFlight();
            break;
        case 4:
            displayFlights();
            break;
        case 5:
            bookTicket();
            break;
        case 6:
            cancelBooking();
            break;
        case 7:
            showBooking();
            break;
        case 8:
            boardingPass();
            break;
        case 9:
            addPilot();
            break;
        case 10:
            addAttendant();
            break;
        case 11:
            assignCrew();
            break;
        case 12:
            displayCrew();
            break;
        case 13:
            waitingList.displayWaitingList();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
    while (ch != 0);
}