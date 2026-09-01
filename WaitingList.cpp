#include "WaitingList.h"
using namespace std;

bool WaitingList::hasPassenger(int passengerID, int flightID) {
    for (int i = 0; i < entries.size(); i++) {
        if (entries[i].passengerID == passengerID && entries[i].flightID == flightID) {
            return true;
        }
    }
    return false;
}

void WaitingList::addPassenger(int passengerID, int flightID) {
    WaitingEntry entry;
    entry.passengerID = passengerID;
    entry.flightID = flightID;
    entries.push_back(entry);

    cout << "Passenger " << passengerID << " added to Waiting List for Flight " << flightID << ".\n";
}

int WaitingList::getFirstPassenger(int flightID) {
    for (int i = 0; i < entries.size(); i++) {
        if (entries[i].flightID == flightID) {
            return entries[i].passengerID;
        }
    }
    return -1;
}

void WaitingList::removeFirstPassenger(int flightID) {
    for (int i = 0; i < entries.size(); i++) {
        if (entries[i].flightID == flightID) {
            entries.erase(entries.begin() + i);
            return;
        }
    }
}

void WaitingList::displayWaitingList() {
    cout << "\n===== Waiting List =====\n";
    if (entries.empty()) {
        cout << "Waiting List is empty.\n";
        return;
    }
    for (int i = 0; i < entries.size(); i++) {
        cout << "Flight ID: " << entries[i].flightID << " | Passenger ID: " << entries[i].passengerID << "\n";
    }
}

bool WaitingList::isEmpty() {
    return entries.empty();
}