#pragma once

#include "Trip.hpp"
#include <vector>

class Logbook {
  private:
    std::vector<Trip> trips;

  public:
    bool addTrip(const Trip &trip);
    bool removeTrip(int tripId);
    bool editTrip(int tripId, const Trip &newTrip);
    std::vector<Trip> getTripsList() const;
};
