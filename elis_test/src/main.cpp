#include <iostream>
#include <string>
#include <sstream>
#include <ncurses.h>

#include "application.h"
#include "exception.h"
#include "ui/window.h"


int main(int argc, char const *argv[])
{
    try
    {
        Elis::Application *app;

        app = new Elis::Application();

        app->initialize(argc, argv);

        app->run();
    }
    catch(Elis::Exception& e)
    {
        std::cerr << "Ops, something went wrong! :(" << std::endl;
        std::cerr << "The error says: " << e.what() << std::endl;

        exit (EXIT_FAILURE);
    }

    return 0;
}
