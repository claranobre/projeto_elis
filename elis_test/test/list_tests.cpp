#include "catch.h"
#include <iostream>

#include "list.cpp"

using namespace Elis;

SCENARIO("we can create an empty list", "[list]")
{
    GIVEN("a list")
    {
        auto list = List<int>();

        THEN("it is empty")
        {
            REQUIRE(list.empty() == true);
        }
    }
}

SCENARIO("we can push front an item", "[list]")
{
    GIVEN("an empty list")
    {
        auto list = List<std::string>();

        REQUIRE(list.empty() == true);

        WHEN("an item is pushed")
        {
            std::string foobar = "foobar";

            list.push_front(foobar);

            THEN("size change by one")
            {
                REQUIRE(list.size() == 1);
            }

            THEN("the first item is foobar")
            {
                REQUIRE(list.front() == "foobar");
            }
        }
    }
}

SCENARIO("we can get the first item", "[list]")
{
    GIVEN("a non empty list")
    {
        auto list = List<std::string>();
        std::string str = "foobar";

        list.push_front(str);

        REQUIRE(list.empty() == false);

        WHEN("first is called")
        {
            std::string first = list.front();

            THEN("we get it")
            {
                REQUIRE(first == "foobar");
            }
        }
    }
}

SCENARIO("we can pop out an item", "[list]")
{
    GIVEN("a non empty list")
    {
        auto list = List<std::string>();

        list.push_front("something");

        REQUIRE(list.empty() == false);
        REQUIRE(list.size() == 1);

        WHEN("an item is front poped out")
        {
            list.pop_front();

            THEN("the size reduces by one")
            {
                REQUIRE(list.size() == 0);
                REQUIRE(list.empty() == true);
            }
        }

        WHEN("an item is back poped out")
        {
            list.pop_back();

            THEN("the size reduces by one")
            {
                REQUIRE(list.size() == 0);
                REQUIRE(list.empty() == true);
            }
        }
    }
}
