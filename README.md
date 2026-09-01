# Airline Reservation System

![C++](https://img.shields.io/badge/C%2B%2B-20-00599C)
![CMake](https://img.shields.io/badge/CMake-3.16%2B-064F8C)
![Build](https://img.shields.io/badge/BUILD-PASSING-brightgreen)
![License](https://img.shields.io/badge/LICENSE-MIT-yellow)

A modular, console-based airline management system written in C++ using Object-Oriented Programming principles, dynamic seat mapping, custom pricing calculations, and an automated waiting list mechanism.

---

## Overview

The **Airline Reservation System** automates core day-to-day flight management operations. It provides role-driven seat booking for **Passengers**, flight scheduling with interactive seat maps, automatic queue management for full flights, dynamic ticket pricing, and polymorphic crew management (Pilots and Flight Attendants).

---

## Features

### Booking & Passenger Management
* **Passenger Registry**: Create and manage passenger profiles and track issued tickets.
* **Seat Map Allocation**: Dynamic seat generation categorized by class (First Class, Business Class, Economy).
* **Boarding Passes**: Issue and render printable boarding passes.

### Smart Waiting List Queue
* **Automated Queueing**: Automatically queue passengers when flight capacity is full.
* **Auto-Promotion**: Re-assign canceled tickets automatically to the first available passenger in queue.

### Flight & Crew Operations
* **Flight Management**: Schedule flights with origin, destination, date, time, and capacity constraints.
* **Polymorphic Aircrew**: Register Pilots and Flight Attendants derived from a base `CrewMember` class and assign them to flights.

### Dynamic Pricing Module
* **Fare Calculation**: Calculate final costs dynamically based on seat class, base fare, dynamic taxes, and applied discounts.

---

## Architecture & OOP Concepts

| Concept | Implementation Details |
| :--- | :--- |
| **Encapsulation** | Protected class member state in `Booking`, `Flight`, and `CrewMember` exposed via safe accessors. |
| **Inheritance** | Derived `Pilot` and `FlightAttendant` classes inheriting from base `CrewMember`. |
| **Polymorphism** | Dynamic method dispatch via `virtual` functions and `CrewMember*` base pointers. |
| **Facade Pattern** | `BookingSystem` acts as a facade controller encapsulating all subsystem managers. |

---

## Project Structure

```text
├── BookingSystem.h / .cpp    # Main system controller and console interface
├── Flight.h / .cpp           # Flight management and seat map layout logic
├── Booking.h / .cpp          # Booking entity definition
├── WaitingList.h / .cpp      # Queue management and automatic promotion logic
├── CrewManager.h / .cpp      # Aircrew assignment and memory lifecycle
├── CrewMember.h / .cpp       # Base class for flight crew
├── Pilot.h / .cpp            # Derived class for pilots
├── FlightAttendant.h / .cpp  # Derived class for flight attendants
├── PassengerManager.h / .cpp # Passenger registry and ticket associations
├── Pricing.h / .cpp          # Pricing calculation engine
└── main.cpp                  # Program entry point
