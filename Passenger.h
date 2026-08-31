#pragma once
#include <string>
#include <vector>

class Passenger {
private:
    int passengerid;
    std::string name, phone, gemail;
    std::vector<int> bookedticketids;

public:
    Passenger(int passengerid = 0, std::string name = "No Name", std::string phone = "No phone",
              std::string gemail = "No gemail");

    int get_id();

    std::string get_name();

    void set_phone(std::string phone);

    void set_name(std::string name);

    void set_gemail(std::string gemail);

    void add_ticket(int id);

    void remove_ticket(int id);

    void display_info();
};
