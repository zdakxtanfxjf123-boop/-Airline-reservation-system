#pragma once
#include "CrewMember.h"
#include <string>
class Pilot : public CrewMember
{
private:
    std::string license;
public:
    Pilot(int id, std::string name, std::string l);
    void displayInfo()const override;
};