#include "Logbook.hpp"
#include "Trip.hpp"
#include "catch.hpp"

TEST_CASE("Logbook operations are functioning", "[logbook]") {
    Logbook logbook;
    Trip trip1(1, "2023-04-01", "08:00", "10:00", 100.0, 150.0, "Business");
    Trip trip2(2, "2023-04-02", "11:00", "12:00", 150.0, 175.0, "Commute");

    SECTION("Add Trip") {
        REQUIRE(logbook.addTrip(trip1) == true);
        auto trips = logbook.getTripsList();
        REQUIRE(trips.size() == 1);
        REQUIRE(trips[0].getTripId() == 1);
    }

    SECTION("Remove Trip") {
        logbook.addTrip(trip1);
        REQUIRE(logbook.removeTrip(1) == true);
        auto trips = logbook.getTripsList();
        REQUIRE(trips.empty() == true);
    }
}
