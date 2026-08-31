#include "WaitingList.h"

void WaitingList::addPassenger(int id)
{
    passengerIDs.push_back(id);

    cout << "Passenger added to Waiting List." << endl;
}

void WaitingList::display()
{
    cout << "\n===== Waiting List =====" << endl;

    if (passengerIDs.empty())
    {
        cout << "Waiting List is empty." << endl;
        return;
    }

    for (int i = 0; i < passengerIDs.size(); i++)
    {
        cout << "Passenger ID: "
             << passengerIDs[i] << endl;
    }
}

int WaitingList::getFirstPassenger()
{
    if (passengerIDs.empty())
        return -1;

    return passengerIDs[0];
}

void WaitingList::removeFirstPassenger()
{
    if (!passengerIDs.empty())
    {
        passengerIDs.erase(passengerIDs.begin());
    }
}

bool WaitingList::isEmpty()
{
    return passengerIDs.empty();
}