#include "CrewMember.h"
#include <iostream>

using namespace std;

CrewMember::CrewMember(int i, string n)
{
    id=i;
    name=n;
    flightId=-1;
}

string CrewMember::getName() const
{
    return name;
}

int CrewMember::getID() const
{
    return id;
}

int CrewMember::getFlightID() const
{
    return flightId;
}

void CrewMember::setFlightID(int fid)
{
    flightId = fid;
}

void CrewMember::displayInfo() const
{
    cout << "Name: " << name << "\nID: " << id << endl;
}