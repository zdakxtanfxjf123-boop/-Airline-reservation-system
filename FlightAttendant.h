#pragma once
#include "CrewMember.h"
#include <string>

class FlightAttendant : public CrewMember
{
private:
    std::string language;

public:
    FlightAttendant(int id, std::string name, std::string l);
    void displayInfo() const override;
};