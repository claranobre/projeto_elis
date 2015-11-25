#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>

#include "ui/window.h"

namespace Elis { class Application; }

class Elis::Application
{
    public:
        Application();
        ~Application();

        void initialize(int argc, char const *argv[]);
        void run();

    private:
        void configure_ncurses();
        void parse_command_line(int argc, char const *argv[]);

    private:
        std::string filename;
        std::string current_line;
        Elis::List<std::string> lines;

        Elis::UI::Window *window;
};

#endif
