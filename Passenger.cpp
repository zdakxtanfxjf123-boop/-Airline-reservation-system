#include "Passenger.h"
#include <iostream>
using namespace std;

Passenger::Passenger(int passengerid, string name, string phone, string gemail) {
    this->passengerid = passengerid;
    this->name = name;
    this->phone = phone;
    this->gemail = gemail;
}

int Passenger::get_id() {
    return passengerid;
}

string Passenger::get_name() {
    return name;
}

void Passenger::add_ticket(int id) {
    bookedticketids.push_back(id);
}

void Passenger::remove_ticket(int id) {
    for (size_t i = 0; i < bookedticketids.size(); i++) {
        if (bookedticketids[i] == id) {
            bookedticketids.erase(bookedticketids.begin() + i);
            cout << "Ticket removed successfully.\n";
            return;
        }
    }
    cout << "Ticket ID not found.\n";
}

void Passenger::display_info() {
    cout << "Name: " << name << "\nID: " << passengerid << "\nPhone: " << phone << "\nEmail: " << gemail << "\n";
}
