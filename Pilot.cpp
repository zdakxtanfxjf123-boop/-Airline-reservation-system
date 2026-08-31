#include "Pilot.h"
#include <iostream>
using namespace std;
Pilot::Pilot(int id, string name, string l) : CrewMember(id, name), license(l)
{
}
void Pilot::displayInfo () const
{
    cout << "Pilot\nID: " << id << "\nName: " << name << "\nLicense: " << license << endl;
}