#include "BookingSystem.h"

BookingSystem::BookingSystem()
{
    nextBookingID = 1;
}

void BookingSystem::addBooking(int passengerID,
                               int flightNumber,
                               string seat,
                               double price)
{
    Booking newBooking(
        nextBookingID,
        passengerID,
        flightNumber,
        seat,
        price
    );

    bookings.push_back(newBooking);

    cout << "Booking added successfully!" << endl;
    cout << "Booking ID: " << nextBookingID << endl;

    nextBookingID++;
}

void BookingSystem::cancelBooking(int bookingID)
{
    for (int i = 0; i < bookings.size(); i++)
    {
        if (bookings[i].getBookingID() == bookingID)
        {
            bookings.erase(bookings.begin() + i);

            cout << "Booking cancelled successfully!"
                 << endl;

            return;
        }
    }

    cout << "Booking not found!" << endl;
}

void BookingSystem::displayBookings()
{
    if (bookings.empty())
    {
        cout << "No bookings found." << endl;
        return;
    }

    for (int i = 0; i < bookings.size(); i++)
    {
        bookings[i].display();
    }
}

void BookingSystem::addToWaitingList(int passengerID)
{
    waitingList.addPassenger(passengerID);
}

void BookingSystem::displayWaitingList()
{
    waitingList.display();
}
void BookingSystem::run()
{
    int choice;
    do
    {
        cout << "\n========================================\n";
        cout << "       AIRLINE RESERVATION SYSTEM       \n";
        cout << "========================================\n";
        cout << "1. Add Booking\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Display All Bookings\n";
        cout << "4. Add Passenger to Waiting List\n";
        cout << "5. Display Waiting List\n";
        cout << "0. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: {
                int passengerID, flightNumber;
                string seat;
                double price;

                cout << "Enter Passenger ID: ";
                cin >> passengerID;
                cout << "Enter Flight Number: ";
                cin >> flightNumber;
                cout << "Enter Seat Number (e.g. A1): ";
                cin >> seat;
                cout << "Enter Ticket Price: ";
                cin >> price;

                addBooking(passengerID, flightNumber, seat, price);
                break;
            }
            case 2: {
                int bookingID;
                cout << "Enter Booking ID to cancel: ";
                cin >> bookingID;
                cancelBooking(bookingID);
                break;
            }
            case 3:
                displayBookings();
                break;
            case 4: {
                int passengerID;
                cout << "Enter Passenger ID for Waiting List: ";
                cin >> passengerID;
                addToWaitingList(passengerID);
                break;
            }
            case 5:
                displayWaitingList();
                break;
            case 0:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    while (choice != 0);
}