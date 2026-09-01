#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <iostream>
#include <vector>

struct WaitingEntry {
    int passengerID;
    int flightID;
};

class WaitingList {
private:
    std::vector<WaitingEntry> entries;

public:
    bool hasPassenger(int passengerID, int flightID);
    void addPassenger(int passengerID, int flightID);
    int getFirstPassenger(int flightID);
    void removeFirstPassenger(int flightID);
    void displayWaitingList();
    bool isEmpty();
};

#endif