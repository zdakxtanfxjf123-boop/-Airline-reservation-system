#pragma once
#include <string>

class CrewMember
{
protected:
    std::string name;
    int id;
    int flightId;

public:
    CrewMember(int i, std::string n);
    virtual ~CrewMember() = default;

    std::string getName() const;
    int getID() const;
    int getFlightID() const;
    void setFlightID(int fid);

    virtual void displayInfo() const;
};