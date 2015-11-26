#include "catch.h"

#include "application.h"

using namespace Elis;

SCENARIO("when the application initializes", "[application]")
{
    GIVEN("an application with parameters")
    {
        auto app = Application();

        WHEN("its initialized")
        {
            int argc = 2;
            char const *argv[2] = { "./app", "foobar.txt" };

            app.initialize(argc, argv);
        }
    }
}
