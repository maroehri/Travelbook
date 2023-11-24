#pragma once

#include "Logbook.hpp"

class UserInterface {
  private:
    Logbook logbook;

  public:
    void start();
    void displayMenu();
    void captureNewTrip();
    void editTrip();
    void deleteTrip();
    void displayTrips();
};
