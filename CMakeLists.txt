cmake_minimum_required(VERSION 3.20)
project(Airline_Reservation_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Airline_Reservation_System
        main.cpp
        Passenger.cpp
        Passenger.h
        CrewManager.cpp
        CrewManager.h
        PassengerManager.cpp
        PassengerManager.h
        Booking.h
        Booking.cpp
        CrewMember.h
        CrewMember.cpp
        Flight.cpp
        Flight.h
        FlightAttendant.cpp
        FlightAttendant.h
        Pilot.cpp
        Pilot.h
        Seat.cpp
        Seat.h
        WaitingList.cpp
        WaitingList.h
        Pricing.cpp
        Pricing.h
        Bookingsystem.cpp
        Bookingsystem.h
)