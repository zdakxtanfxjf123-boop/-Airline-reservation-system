#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <iostream>
#include <string>
using namespace std;

class CrewMember
{
protected:
    string name;
    int id;
    bool assigned;

public:
    CrewMember(string n, int i);

    virtual void display();

    string getName();

    int getID();

    bool isAssigned();

    void setAssigned(bool value);
};

class Pilot : public CrewMember
{
public:

    Pilot(string n, int i);

    void display() override;
};

class FlightAttendant : public CrewMember
{
public:

    FlightAttendant(string n, int i);

    void display() override;
};

#endif