#pragma once
#include <vector>
#include "CrewMember.h"

class CrewManager
{
private:
    std::vector<CrewMember*> crewList;

public:
    ~CrewManager();
    void addCrew(CrewMember* c);
    void assignCrewToFlight(int cid, int fid);
    void displayCrewForFlight(int fid);
};