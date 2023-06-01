#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <arrayd/arrayd.hpp>

#include <sstream>

TEST_CASE("_") {
    ArrayD r;
    std::stringstream sstrm;

    SUBCASE("Trash") {
        sstrm.str("-5");
        sstrm >> r;
        CHECK(sstrm.fail());
        CHECK(!sstrm.bad());
    }

    sstrm.clear();
}
