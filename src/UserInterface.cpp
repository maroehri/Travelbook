#include "UserInterface.hpp"
#include <iostream>
#include <string>
#include <vector>

void UserInterface::start() {
    int choice = 0;
    while (choice != 5) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            captureNewTrip();
            break;
        case 2:
            editTrip();
            break;
        case 3:
            deleteTrip();
            break;
        case 4:
            displayTrips();
            break;
        case 5:
            // Exit
            break;
        default:
            std::cout << "Invalid option, please try again." << std::endl;
        }
    }
}

void UserInterface::displayMenu() {
    std::cout << "\nLogbook Application" << std::endl;
    std::cout << "1. Add New Trip" << std::endl;
    std::cout << "2. Edit Trip" << std::endl;
    std::cout << "3. Delete Trip" << std::endl;
    std::cout << "4. Display All Trips" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Please select an option: ";
}

void UserInterface::captureNewTrip() {
    int id;
    std::string date, start, end, purpose;
    double startMileage, endMileage;

    std::cout << "Enter Trip-ID: ";
    std::cin >> id;
    std::cin.ignore(); // Ignore remaining newline character in input stream

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Enter start time (HH:MM): ";
    std::getline(std::cin, start);

    std::cout << "Enter end time (HH:MM): ";
    std::getline(std::cin, end);

    std::cout << "Enter starting mileage: ";
    std::cin >> startMileage;

    std::cout << "Enter ending mileage: ";
    std::cin >> endMileage;
    std::cin.ignore(); // Ignore remaining newline character in input stream

    std::cout << "Enter purpose of the trip: ";
    std::getline(std::cin, purpose);

    Trip newTrip(id, date, start, end, startMileage, endMileage, purpose);
    if (logbook.addTrip(newTrip)) {
        std::cout << "Trip successfully added." << std::endl;
    } else {
        std::cout << "Error adding the trip." << std::endl;
    }
}

void UserInterface::editTrip() {
    // Editing a trip could be implemented similarly to captureTrip()
}

void UserInterface::deleteTrip() {
    int id;
    std::cout << "Enter the ID of the trip to be deleted: ";
    std::cin >> id;

    if (logbook.removeTrip(id)) {
        std::cout << "Trip successfully deleted." << std::endl;
    } else {
        std::cout << "Trip with ID " << id << " was not found."
                  << std::endl;
    }
}

void UserInterface::displayTrips() {
    auto trips = logbook.getTripsList();
    for (const auto &trip : trips) {
        std::cout << "\n" << trip.getDetails() << "\n" << std::endl;
    }
}
