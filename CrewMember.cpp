#include "CrewMember.h"

CrewMember::CrewMember(string n, int i)
{
    name = n;
    id = i;
    assigned = false;
}

void CrewMember::display()
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}

string CrewMember::getName()
{
    return name;
}

int CrewMember::getID()
{
    return id;
}

bool CrewMember::isAssigned()
{
    return assigned;
}

void CrewMember::setAssigned(bool value)
{
    assigned = value;
}

Pilot::Pilot(string n, int i) : CrewMember(n, i)
{
}

void Pilot::display()
{
    cout << "Pilot Name: " << name << endl;
    cout << "Pilot ID: " << id << endl;
}

FlightAttendant::FlightAttendant(string n, int i) : CrewMember(n, i)
{
}

void FlightAttendant::display()
{
    cout << "Flight Attendant Name: " << name << endl;
    cout << "Flight Attendant ID: " << id << endl;
}