#include "Trip.hpp"
#include <sstream>

Trip::Trip(int id, std::string date, std::string start, std::string end,
           double startMile, double endMile, std::string purp)
    : tripId(id), date(date), startTime(start), endTime(end),
      startMileage(startMile), endMileage(endMile), purpose(purp) {}

int Trip::getTripId() const {
    return tripId;
}

std::string Trip::getDate() const {
    return date;
}

std::string Trip::getStartTime() const {
    return startTime;
}

std::string Trip::getEndTime() const {
    return endTime;
}

double Trip::getStartMileage() const {
    return startMileage;
}

double Trip::getEndMileage() const {
    return endMileage;
}

std::string Trip::getPurpose() const {
    return purpose;
}

double Trip::calculateDistance() const {
    return endMileage - startMileage; // simple distance calculation
}

std::string Trip::getDetails() const {
    std::stringstream details;
    details << "Trip ID: " << tripId << "\n"
            << "Datum: " << date << "\n"
            << "Start Zeit: " << startTime << "\n"
            << "Ende Zeit: " << endTime << "\n"
            << "Start km: " << startMileage << "\n"
            << "Ende km: " << endMileage << "\n"
            << "Zweck: " << purpose << "\n"
            << "Distanz: " << calculateDistance() << " km";
    return details.str();
}
