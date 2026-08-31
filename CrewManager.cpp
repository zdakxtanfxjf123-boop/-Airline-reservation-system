#include "CrewManager.h"
#include <iostream>

using namespace std;

CrewManager::~CrewManager()
{
    for (auto c : crewList)
    {
        delete c;
    }
    crewList.clear();
}

void CrewManager::addCrew(CrewMember* c)
{
    for (auto x : crewList)
    {
        if (x->getID() == c->getID())
        {
            cout << "Crew ID already exists!\n";
            delete c;
            return;
        }
    }
    crewList.push_back(c);
    cout << "Crew member added successfully.\n";
}

void CrewManager::assignCrewToFlight(int cid, int fid)
{
    for (auto c : crewList)
    {
        if (c->getID() == cid)
        {
            if (c->getFlightID() != -1)
            {
                cout << "Crew member is already assigned to a flight.\n";
                return;
            }
            c->setFlightID(fid);
            cout << "Crew assigned successfully.\n";
            return;
        }
    }
    cout << "Crew member not found.\n";
}

void CrewManager::displayCrewForFlight(int fid)
{
    bool found = false;
    for (auto c : crewList)
    {
        if (c->getFlightID() == fid)
        {
            c->displayInfo();
            cout << "Flight ID: " << fid << "\n--------------------\n";
            found = true;
        }
    }
    if (!found) cout << "No crew assigned to this flight.\n";
}