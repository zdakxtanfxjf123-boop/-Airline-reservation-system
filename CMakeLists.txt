cmake_minimum_required(VERSION 4.2)
project(Airline_Reservation_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Airline_Reservation_System main.cpp
        Passenger.cpp
        Passenger.h
        PassengerManager.cpp
        PassengerManager.h

