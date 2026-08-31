#include "FlightAttendant.h"
#include <iostream>

using namespace std;

FlightAttendant::FlightAttendant(int id, string name, string l) : CrewMember(id, name), language(l)
{
}

void FlightAttendant::displayInfo() const
{
    cout << "Flight Attendant\nID: " << id << "\nName: " << name << "\nLanguage: " << language << endl;
}