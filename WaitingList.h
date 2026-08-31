#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <iostream>
#include <vector>
using namespace std;

class WaitingList
{
private:
    vector<int> passengerIDs;

public:
    void addPassenger(int id);
    void display();
    int getFirstPassenger();
    void removeFirstPassenger();
    bool isEmpty();
};

#endif