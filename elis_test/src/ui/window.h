#ifndef _WINDOW_
#define _WINDOW_

#include <ncurses.h>

#include "list.cpp"
#include "line.h"

namespace Elis
{
    namespace UI { class Window; }
}

class Elis::UI::Window
{
    public:
        Window();
        ~Window();

        void show();
        void hide();
        Elis::UI::Line new_line(const char *c = "");

    private:
        WINDOW *window;
        Elis::UI::Line *current_line;
        Elis::List<Elis::UI::Line> *lines;
};

#endif
