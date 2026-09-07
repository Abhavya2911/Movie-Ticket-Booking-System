# Movie Ticket Booking System (C++)

A C++ Object-Oriented System Design implementation of a Cinema Hall Ticket Booking Engine. This project models the core components of a modern cinema booking platform—including multi-screen management, seat tier pricing, dynamic seat state tracking per show, flexible payment processing, and ticket generation.

---

## Key Features

* **Multi-Screen & Show Scheduling:** Supports multiple screens with independent physical seating layouts and separate movie showtimes.
* **Tiered Seat Pricing:** Seat categories categorized into `SILVER`, `GOLD`, and `PLATINUM` tiers with distinct pricing structures.
* **Dynamic Seat State Tracking:** Seat availability (`AVAILABLE` vs. `BOOKED`) is tracked dynamically per show using `ShowSeat` wrappers, preserving physical seat configurations across multiple showtimes.
* **Atomic Seat Allocation:** Ensures all requested seats are available prior to confirmation; if any seat is already booked, the entire transaction is safely rejected.
* **Extensible Payment System:** Abstract base `Payment` interface supporting multiple concrete methods (`UpiPayment`, `CardPayment`, and `CashPayment`).
* **Ticket Generation:** Formatted receipt output generated via `TicketPrinter` upon successful booking confirmation.

---

## Object-Oriented & Design Principles

This project was built following Object-Oriented Analysis and Design (OOAD) fundamentals and SOLID principles:

* **Single Responsibility Principle (SRP):** Classes are focused on single domains. For instance, `TicketPrinter` solely formats output, `ShowSeat` strictly manages state per show instance, and `Seat` holds physical attributes.
* **Open/Closed Principle (OCP):** New payment channels (e.g., `NetBankingPayment`) can be added by deriving from the abstract `Payment` class without modifying existing service or domain code.
* **Dependency Inversion Principle (DIP):** High-level booking orchestrators depend on abstract interfaces (`Payment`) rather than concrete implementations.
* **Composition over Inheritance:** Physical entities (`Screen` owning physical `Seat` objects; `Show` owning runtime `ShowSeat` objects) are modeled using strict composition life-cycle guarantees.

---

## File Structure

.
├── Seat.cpp            # Defines physical seat properties (number, tier type, base price)
├── Screen.cpp          # Manages screen number and collection of physical seats
├── ShowSeat.cpp        # Tracks seat state (AVAILABLE/BOOKED) for a specific show instance
├── Show.cpp            # Links a Movie, Screen, start time, and manages ShowSeat collection
├── TicketPrinter.cpp   # Handles formatted ticket rendering on output stream
└── README.md           # Project documentation

---

## Compilation & Execution

# Prerequisites
Any C++ compiler supporting standard C++11 or higher (g++, clang++, or MSVC).

Building with g++
# To compile all system files together:
g++ -std=c++11 -Wall Seat.cpp Screen.cpp ShowSeat.cpp Show.cpp TicketPrinter.cpp main.cpp -o movie_booking

# Running the executable:
./movie_booking

# SAMPLE OUTPUT:

====================================
             TICKET
====================================
Booking ID : BK1001
Movie      : Spider-Man:Brand New Day
Screen     : Screen-1
Time       : 05:00 PM
Seats      : A1 A2 
Amount     : Rs.300
Status     : CONFIRMED
====================================


