#pragma once
#include <vector>
#include <string>
#include "Passenger.h"

class PassengerManager {
private:
    std::vector<Passenger> passengers_List;
    int autogenerate = 100;

    int search_passenger_index(int id);
public:
    bool passenger_Exists(int id);
    void add_passengarinfo();
    void display_passenger(int id);
    void book_ticket_for_passenger(int id, int ticket);
    void cancel_ticket_for_passenger(int id, int ticket);
    void print_board_pass(int id, std::string &seat);
};
