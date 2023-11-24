#define CATCH_CONFIG_MAIN
#include "Trip.hpp"
#include "catch.hpp"

TEST_CASE("Trip calculations are correct", "[trip]") {
    Trip trip(1, "2023-11-08", "08:00", "10:00", 100.0, 150.0, "Business");

    SECTION("Calculate distance") {
        REQUIRE(trip.calculateDistance() == 50.0);
    }

    SECTION("Get trip details") {
        REQUIRE(trip.getDate() == "2023-11-08");
        REQUIRE(trip.getStartTime() == "08:00");
        REQUIRE(trip.getEndTime() == "10:00");
        REQUIRE(trip.getStartMileage() == 100.0);
        REQUIRE(trip.getEndMileage() == 150.0);
        REQUIRE(trip.getPurpose() == "Business");
    }
}
