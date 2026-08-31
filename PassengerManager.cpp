#include "PassengerManager.h"
#include <iostream>
using namespace std;

int PassengerManager::search_passenger_index(int id) {
    for (int i = 0; i < passengers_List.size(); i++) {
        if (passengers_List[i].get_id() == id) return i;
    }
    return -1;
}

bool PassengerManager::passenger_Exists(int id) {
    return search_passenger_index(id) != -1;
}

void PassengerManager::add_passengarinfo() {
    int choice, id;
    cout << "1. Auto-generate ID\n2. Manual ID\nChoice: ";
    cin >> choice;
    if (choice == 1) {
        id = autogenerate++;
    } else if (choice == 2) {
        cout << "Enter Manual ID: ";
        cin >> id;
        if (search_passenger_index(id) != -1) {
            cout << "Error: ID already exists! Operation canceled.\n";
            return;
        }
        if (id >= autogenerate)autogenerate = id + 1;
    } else {
        cout << "please Enter valid choice\n";
        return;
    }
    cin.ignore();
    cout << "Enter your name \n";
    string name;
    getline(cin, name);
    cout << "Enter your phone \n";
    string phone;
    cin >> phone;
    cout << "Enter your gemail\n";
    string gemail;
    cin >> gemail;
    Passenger newpassenger(id, name, phone, gemail);
    passengers_List.push_back(newpassenger);
    cout << "Passenger added successfully with ID: " << id << endl;
}

void PassengerManager::display_passenger(int id) {
    int i = search_passenger_index(id);
    if (i == -1)
        cout << "Passenger not found!\n";
    else
        passengers_List[i].display_info();
}

void PassengerManager::book_ticket_for_passenger(int id, int ticket) {
    int i = search_passenger_index(id);
    if (i != -1) passengers_List[i].add_ticket(ticket);
}

void PassengerManager::cancel_ticket_for_passenger(int id, int ticket) {
    int i = search_passenger_index(id);
    if (i != -1) passengers_List[i].remove_ticket(ticket);
}

void PassengerManager::print_board_pass(int id, std::string &seat) {
    int i = search_passenger_index(id);
    if (i == -1) {
        cout << "Passenger not found!\n";
        return;
    }
    cout << "\n========================================\nBOARDING PASS\n========================================\n";
    cout << "Passenger ID : " << passengers_List[i].get_id()
            << "\nName : " << passengers_List[i].get_name()
            << "\nSeat : " << seat
            << "\n==================================================================================================\n";
}
